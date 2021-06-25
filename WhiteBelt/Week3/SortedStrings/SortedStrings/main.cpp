//
//  main.cpp
//  SortedStrings
//
//  Created by Boris Tarovik on 24.06.2021.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
      v.push_back(s);
      sort(begin(v), end(v), [](string s1, string s2) {
          return s1 < s2;
      });
  }
  vector<string> GetSortedStrings() {
      return v;
  }
private:
    vector<string> v;
};
