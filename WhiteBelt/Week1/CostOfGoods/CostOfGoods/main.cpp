//
//  main.cpp
//  CostOfGoods
//
//  Created by Boris Tarovik on 23.05.2021.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    
    if (n > b) {
        cout << n * (1.0 - y / 100.0) ;
    } else if (n > a) {
        cout << n * (1.0 - x / 100.0);
    }
    else {
        cout << n;
    }
    return 0;
}
