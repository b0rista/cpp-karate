//
//  main.cpp
//  Names2
//
//  Created by Boris Tarovik on 24.06.2021.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string combaineHistoryInString(const vector<string>& history) {
    string historyString = "";
    
    for (int i = (int)history.size() - 1; i >= 0; --i) {
        if (historyString == "") {
            historyString += "(";
        } else {
            historyString += ", ";
        }
        historyString += history[i];
    }
    if (historyString != "") {
        historyString += ")";
    }
    
    return historyString;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        year2name[year] = first_name;
    }
    
    void ChangeLastName(int year, const string& last_name) {
        year2surname[year] = last_name;
    }
    
    string GetFullName(int year) {
        string name = "";
        for (const auto& i: year2name) {
            if (i.first <= year) {
              name = i.second;
            }
            else {
              break;
            }
        }

        string surname = "";
        for (const auto& i: year2surname) {
            if (i.first <= year) {
              surname = i.second;
            }
            else {
              break;
            }
        }

        if (surname == "" && name == "") {
            return "Incognito";
        }
        else if (surname == "" && name != "") {
            return name + " with unknown last name";
        }
        else if (surname != "" && name == "") {
            return surname + " with unknown first name";
        }
        else {
            return name + " " + surname;
        }
    }
    
    string GetFullNameWithHistory(int year) {
        string name = "";
        vector<string> nameHistory;
        
        for (const auto& i: year2name) {
            if (i.first <= year) {
                if (name != "" && name != i.second) {
                    nameHistory.push_back(name);
                }
                name = i.second;
            }
            else {
                break;
            }
        }
        
        string nameHistoryString = combaineHistoryInString(nameHistory);
        
        if (nameHistoryString != "") {
            name += " " + nameHistoryString;
        }
        
        
        string surname = "";
        vector<string> surnameHistory;
        
        for (const auto& i: year2surname) {
            if (i.first <= year) {
                if (surname != "" && surname != i.second) {
                    surnameHistory.push_back(surname);
                }
                surname = i.second;
            }
            else {
                break;
            }
        }
        
        string surnameHistoryString = combaineHistoryInString(surnameHistory);
        
        if (surnameHistoryString != "") {
            surname += " " + surnameHistoryString;
        }
        
        if (surname == "" && name == "") {
            return "Incognito";
        }
        else if (surname == "" && name != "") {
            return name + " with unknown last name";
        }
        else if (surname != "" && name == "") {
            return surname + " with unknown first name";
        }
        else {
            return name + " " + surname;
        }
    }
    
private:
  // приватные поля
    map<int, string> year2name;
    map<int, string> year2surname;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeFirstName(1965, "Appolinaria");

  person.ChangeLastName(1965, "Sergeeva");
  person.ChangeLastName(1965, "Volkova");
  person.ChangeLastName(1965, "Volkova-Sergeeva");

  for (int year : {1964, 1965, 1966}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
