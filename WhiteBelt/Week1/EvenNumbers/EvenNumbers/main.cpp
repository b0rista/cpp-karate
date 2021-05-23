//
//  main.cpp
//  EvenNumbers
//
//  Created by Boris Tarovik on 23.05.2021.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int a, b;
    cin >> a >> b;
    
    for (int i = a; i <= b; ++i) {
        if (i % 2 == 0) {
            cout << i << ' ';
        }
    }
    return 0;
}
