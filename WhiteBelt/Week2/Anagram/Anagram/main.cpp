//
//  main.cpp
//  Anagram
//
//  Created by Boris Tarovik on 20.06.2021.
//

#include <iostream>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& s) {
    map<char, int> charCounters;
    for (auto c : s) {
        ++charCounters[c];
    }
    return charCounters;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        if (BuildCharCounters(s1) == BuildCharCounters(s2)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
