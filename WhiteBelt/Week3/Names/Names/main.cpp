//
//  main.cpp
//  Names
//
//  Created by Boris Tarovik on 24.06.2021.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
      year2name[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
      year2surname[year] = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
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
private:
  // приватные поля
    map<int, string> year2name;
    map<int, string> year2surname;
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}
