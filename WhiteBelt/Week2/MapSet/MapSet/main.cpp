//
//  main.cpp
//  MapSet
//
//  Created by Boris Tarovik on 22.06.2021.
//

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> s;
    
    for (auto el : m) {
        s.insert(el.second);
    }
    
    return s;
}

