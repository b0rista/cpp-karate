//
//  main.cpp
//  MinString
//
//  Created by Boris Tarovik on 23.05.2021.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string a, b, c;
    cin >> a >> b >> c;
    
    string minString = a;
    if (b < minString) {
        minString = b;
    }
    if (c < minString) {
        minString = c;
    }
    cout << minString;
    
    return 0;
}
