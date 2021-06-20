//
//  main.cpp
//  MonthlyTasks
//
//  Created by Boris Tarovik on 20.06.2021.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int monthIdx = 0;
    vector<vector<string>> tasks(daysInMonths[monthIdx]);
    
    int q;
    cin >> q;
    for (int k = 0; k < q; ++k) {
        string operation;
        cin >> operation;
        if (operation == "ADD") {
            int i;
            string s;
            cin >> i >> s;
            
            tasks[i-1].push_back(s);
            
        }
        else if (operation == "DUMP") {
            int i;
            cin >> i;
            cout << tasks[i-1].size() << ' ';
            for (auto task : tasks[i-1]) {
                cout << task << ' ';
            }
            cout << endl;
        }
        else if (operation == "NEXT") {
            int nextMonthIdx = (monthIdx + 1) % daysInMonths.size();
            
            vector<string> leftTasks;
            int daysCountDiff = daysInMonths[monthIdx] - daysInMonths[nextMonthIdx];
            for (int j = daysInMonths[monthIdx] - 1; j > daysInMonths[monthIdx] - 1 - daysCountDiff; --j) {
                for (auto task : tasks[j]) {
                    leftTasks.push_back(task);
                }
            }
            
            tasks.resize(daysInMonths[nextMonthIdx]);
            
            for (auto task : leftTasks) {
                tasks[tasks.size() - 1].push_back(task);
            }
            
            monthIdx = nextMonthIdx;
        }
    }
    
    
    return 0;
}
