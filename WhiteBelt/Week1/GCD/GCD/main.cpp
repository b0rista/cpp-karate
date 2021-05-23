//
//  main.cpp
//  GCD
//
//  Created by Boris Tarovik on 23.05.2021.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int a, b;
    cin >> a >> b;
    
    // Euclidean algorithm
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    cout << a + b;
    
    return 0;
}
