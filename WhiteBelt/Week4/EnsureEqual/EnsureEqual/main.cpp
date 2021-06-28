//
//  main.cpp
//  EnsureEqual
//
//  Created by Boris Tarovik on 28.06.2021.
//

#include <iostream>
#include <string>
#include <exception>

using namespace std;

void EnsureEqual(const string& left, const string& right) {
    if (left != right) {
        string errorMsg = left + " != " + right;
        throw runtime_error(errorMsg);
    }
}

int main() {
  try {
    EnsureEqual("C++ White", "C++ White");
    EnsureEqual("C++ White", "C++ Yellow");
  } catch (runtime_error& e) {
    cout << e.what() << endl;
  }
  return 0;
}
