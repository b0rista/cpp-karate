//
//  main.cpp
//  TaskTracker
//
//  Created by Boris Tarovik on 04.07.2021.
//

#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <stdexcept>

using namespace std;


enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

using TasksInfo = map<TaskStatus, int>;

void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}



int countTaskStatus(const TasksInfo& info, TaskStatus status) {
    if (info.count(status) > 0) {
        return info.at(status);
    }
    else {
        return 0;
    }
}



void moveTasks(TasksInfo& from, TasksInfo& to, TaskStatus status, int nTasks) {
    from[status] -= nTasks;
    if (from[status] == 0) {
        from.erase(status);
    }
    else if (from[status] < 0) {
        throw logic_error("Task count can't be negative");
    }
    
    switch (status) {
        case TaskStatus::NEW:
            to[TaskStatus::IN_PROGRESS] += nTasks;
            break;
        case TaskStatus::IN_PROGRESS:
            to[TaskStatus::TESTING] += nTasks;
            break;
        case TaskStatus::TESTING:
            to[TaskStatus::DONE] += nTasks;
            break;
        default:
            break;
    }
}

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return person2taskInfo.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person) {
        ++(person2taskInfo[person][TaskStatus::NEW]);
    }
    
    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int taskCount) {
        if (person2taskInfo.count(person) == 0) {
            return make_tuple(TasksInfo(), TasksInfo());
        }
        
        const TasksInfo& personCurrentTasks = GetPersonTasksInfo(person);
        
        int nUndoneTasks = countTaskStatus(personCurrentTasks, TaskStatus::NEW)
            + countTaskStatus(personCurrentTasks, TaskStatus::IN_PROGRESS)
            + countTaskStatus(personCurrentTasks, TaskStatus::TESTING);
        
        
        int nTasksToUpdate = (nUndoneTasks < taskCount) ? nUndoneTasks : taskCount;
        
        TasksInfo updatedTasks;
        TasksInfo leftTasks = personCurrentTasks;
        if (leftTasks.count(TaskStatus::DONE) > 0) {
            leftTasks.erase(TaskStatus::DONE);
        }
            
        for (const auto& item: personCurrentTasks) {
            if (nTasksToUpdate == 0) {
                break;
            }
            
            int possibleToMove = (item.second <= nTasksToUpdate) ? item.second : nTasksToUpdate;
            moveTasks(leftTasks, updatedTasks, item.first, possibleToMove);
            nTasksToUpdate -= possibleToMove;
        }
        
        TasksInfo newTasksList = leftTasks;
        for (const auto& item: updatedTasks) {
            newTasksList[item.first] += item.second;
        }
        if (personCurrentTasks.count(TaskStatus::DONE) > 0) {
            newTasksList[TaskStatus::DONE] += personCurrentTasks.at(TaskStatus::DONE);
        }
        
        person2taskInfo[person] = newTasksList;
        
        return make_tuple(updatedTasks, leftTasks);
    }
    
private:
    map<string, TasksInfo> person2taskInfo;
};

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

  TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}
