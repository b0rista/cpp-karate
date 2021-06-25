//
//  main.cpp
//  SortLower
//
//  Created by Boris Tarovik on 24.06.2021.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto& i: v) {
        cin >> i;
    }
    
    
    sort(begin(v), end(v), [](const string& s1, const string& s2) {
       return lexicographical_compare(begin(s1), end(s1),
                                      begin(s2), end(s2), [](char c1, char c2) {
           return tolower(c1) < tolower(c2);
       });
    });
    
    /*
     sort(begin(v), end(v), [](string a, string b) {
        string lowerA = a, lowerB = b;
        for (auto& c: lowerA) {
            c = tolower(c);
        }
        for (auto& c: lowerB) {
            c = tolower(c);
        }
        return lowerA < lowerB;
     });
     */
    
    for (const auto& i: v) {
        cout << i << ' ';
    }

    return 0;
}
