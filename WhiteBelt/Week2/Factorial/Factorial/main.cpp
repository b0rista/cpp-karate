//
//  main.cpp
//  Factorial
//
//  Created by Boris Tarovik on 18.06.2021.
//

#include <iostream>

int Factorial(int n) {
    int fact = 1;
    
    for (int x = 2; x <= n; ++x) {
        fact *= x;
    }
    
    return fact;
}

int main(int argc, const char * argv[]) {
    return 0;
}
