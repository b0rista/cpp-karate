//
//  main.cpp
//  Division
//
//  Created by Boris Tarovik on 23.05.2021.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int a, b;
    cin >> a >> b;
    if (b == 0) {
        cout << "Impossible";
    }
    else {
        cout << a / b;
    }
}
