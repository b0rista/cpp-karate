//
//  main.cpp
//  UniqueStrings
//
//  Created by Boris Tarovik on 22.06.2021.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    set<string> uniqueStrings;
    while (n > 0) {
        string s;
        cin >> s;
        uniqueStrings.insert(s);
        --n;
    }
    
    cout << uniqueStrings.size() << endl;
    
    
    return 0;
}
