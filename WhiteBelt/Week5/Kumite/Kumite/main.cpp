//
//  main.cpp
//  Kumite
//
//  Created by Boris Tarovik on 28.06.2021.
//

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <exception>

using namespace std;

struct Year {
    int value;
    explicit Year(int newValue) {
        value = newValue;
    }
};

struct Month {
    int value;
    explicit Month(int newValue) {
        value = newValue;
    }
};

struct Day {
    int value;
    explicit Day(int newValue) {
        value = newValue;
    }
};

class Date {
public:
    Date(Year newYear, Month newMonth, Day newDay) {
        year = newYear.value;
        month = newMonth.value;
        day = newDay.value;
    }
    
    int GetYear() const {
        return year;
    }
    
    int GetMonth() const {
        return month;
    }
    
    int GetDay() const {
        return day;
    }
    
private:
    int year, month, day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    }
    else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    }
    else {
        return lhs.GetDay() < rhs.GetDay();
    }
}

ostream& operator<<(ostream& stream, const Date& date) {
    cout << setfill('0');
    cout << setw(4) << date.GetYear() << '-' << setw(2) << date.GetMonth() << '-' << setw(2) << date.GetDay();
    return stream;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        date2events[date].insert(event);
    }
    
    bool DeleteEvent(const Date& date, const string& event) {
        if (date2events.count(date) > 0) {
            if (date2events[date].count(event) > 0) {
                date2events[date].erase(event);
                return true;
            }
            return false;
        }
        return false;
    }
    
    int DeleteDate(const Date& date) {
        if (date2events.count(date) > 0) {
            int nDeleted = (int)date2events[date].size();
            date2events.erase(date);
            return nDeleted;
        }
        return 0;
    }

    void Find(const Date& date) const {
        if (date2events.count(date) > 0) {
            for (const auto& event: date2events.at(date)) {
                cout << event << endl;
            }
        }
    }
  
    void Print() const {
        for (const auto& item: date2events) {
            for (const auto& event: item.second) {
                cout << item.first << ' ' << event << endl;
            }
        }
    };
    
private:
    map<Date, set<string>> date2events;
};

Date createDate(string dateString) {
    int year, month, day;
    char delim1, delim2;
    
    istringstream ss(dateString);
    ss >> year >> delim1 >> month >> delim2 >> day;
    
    if (delim1 != '-' || delim2 != '-' || !ss || ss.peek() != -1) {
        throw runtime_error("Wrong date format: " + dateString);
    }
    else {
        return Date(Year{year}, Month{month}, Day{day});
    }
}

bool validateDate(const Date& date) {
    if (date.GetMonth() < 1 || date.GetMonth() > 12) {
        cout << "Month value is invalid: " << date.GetMonth() << endl;
        return false;
    }
    if (date.GetDay() < 1 || date.GetDay() > 31) {
        cout << "Day value is invalid: " << date.GetDay() << endl;
        return false;
    }
    return true;
}

int main() {
    Database db;
    
    set<string> commandsWithDate = {"Add", "Del", "Find"};
    
    string command;
    while (getline(cin, command)) {
        if (command.empty()) {
            continue;
        }

        istringstream ss(command);
        string action;
        ss >> action;
        ss.ignore(1);
        
        if (commandsWithDate.count(action) > 0) {
            string dateString;
            ss >> dateString;
            try {
                Date date = createDate(dateString);
                if (validateDate(date)) {
                    if ("Add" == action) {
                        string event;
                        ss >> event;
                        db.AddEvent(date, event);
                    }
                    else if ("Del" == action) {
                        if (ss.peek() == ' ') {
                            string event;
                            ss >> event;
                            bool success = db.DeleteEvent(date, event);
                            if (success) {
                                cout << "Deleted successfully" << endl;
                            }
                            else {
                                cout << "Event not found" << endl;
                            }
                        }
                        else {
                            int nDeleted = db.DeleteDate(date);
                            cout << "Deleted " << nDeleted << " events" << endl;
                        }
                    }
                    else {
                        db.Find(date);
                    }
                }
            } catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
        }
        else if ("Print" == action) {
            db.Print();
        }
        else {
            cout << "Unknown command: " << action << endl;
        }
  }

  return 0;
}
