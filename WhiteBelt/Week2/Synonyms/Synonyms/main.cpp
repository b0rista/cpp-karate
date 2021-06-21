//
//  main.cpp
//  Synonyms
//
//  Created by Boris Tarovik on 22.06.2021.
//

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    map<string, set<string>> synonyms;
    
    int q;
    cin >> q;
    while (q > 0) {
        string s;
        cin >> s;
        if (s == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            synonyms[word1].insert(word2);
            synonyms[word2].insert(word1);
        }
        else if (s == "COUNT") {
            string word;
            cin >> word;
            cout << synonyms[word].size() << endl;
        }
        else if (s == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            if (synonyms[word1].count(word2) > 0) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        
        --q;
    }
    
    
    return 0;
}
