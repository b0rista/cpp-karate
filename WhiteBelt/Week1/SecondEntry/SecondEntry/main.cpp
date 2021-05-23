//
//  main.cpp
//  SecondEntry
//
//  Created by Boris Tarovik on 23.05.2021.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    cin >> s;
    
    int fIndex = -2;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'f') {
            if (fIndex == -2) {
                fIndex = -1;
            }
            else if (fIndex == -1) {
                fIndex = i;
            }
            else {
                break;
            }
        }
    }
    
    cout << fIndex;
    
    
    return 0;
}
