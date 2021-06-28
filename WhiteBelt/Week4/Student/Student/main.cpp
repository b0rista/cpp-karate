//
//  main.cpp
//  Student
//
//  Created by Boris Tarovik on 26.06.2021.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    int day;
    int month;
    int year;
};

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<Student> students(n);
    for (auto& student: students) {
        string firstName;
        string lastName;
        int day;
        int month;
        int year;
        cin >> firstName >> lastName >> day >> month >> year;
        student = {firstName, lastName, day, month, year};
    }
    
    int m;
    cin >> m;
    while (m > 0) {
        string request;
        int k;
        cin >> request >> k;
        if (k > students.size() || k < 1) {
            cout << "bad request" << endl;
        }
        else {
            const Student& kthStudent = students[k-1];
            
            if (request == "name") {
                cout << kthStudent.firstName << ' ' << kthStudent.lastName << endl;
            }
            else if (request == "date") {
                cout << kthStudent.day << '.' << kthStudent.month << '.' << kthStudent.year << endl;
            }
            else {
                cout << "bad request" << endl;
            }
        }
        
        --m;
    }
    
    
    return 0;
}
