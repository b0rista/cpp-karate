//
//  main.cpp
//  Palindrom
//
//  Created by Boris Tarovik on 18.06.2021.
//

#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string s) {
    int leftIdx = 0;
    int rightIdx = (int)s.size() - 1;
    
    while (rightIdx > leftIdx) {
        if (s[leftIdx] != s[rightIdx]) {
            return false;
        }
        ++leftIdx;
        --rightIdx;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    cout << IsPalindrom("madam");
    cout << IsPalindrom("gentleman");
    cout << IsPalindrom("X");
    cout << IsPalindrom("");
    return 0;
}
