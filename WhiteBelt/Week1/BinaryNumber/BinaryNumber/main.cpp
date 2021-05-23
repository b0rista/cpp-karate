//
//  main.cpp
//  BinaryNumber
//
//  Created by Boris Tarovik on 23.05.2021.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int d;
    cin >> d;
    
    vector<int> b;
    while (d > 0) {
        b.push_back(d % 2);
        d = d / 2;
    }
    for (int i = b.size() - 1; i >= 0; --i) {
        cout << b[i];
    }
    
    
    return 0;
}
