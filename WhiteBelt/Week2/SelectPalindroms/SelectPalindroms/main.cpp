//
//  main.cpp
//  SelectPalindroms
//
//  Created by Boris Tarovik on 18.06.2021.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPalindrom(string s) {
    // Замечание: более правильным было бы использовать здесь тип size_t вместо int
    // О причинах Вы узнаете на Жёлтом поясе
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> filteredPalindroms;
    
    for (auto w : words) {
        if (IsPalindrom(w) && w.size() >= minLength) {
            filteredPalindroms.push_back(w);
        }
    }
    
    return filteredPalindroms;
}

int main(int argc, const char * argv[]) {
    PalindromFilter({"abacaba", "aba"}, 5);
    PalindromFilter({"abacaba", "aba"}, 2);
    return 0;
}
