//
//  main.cpp
//  FixedPrecision
//
//  Created by Boris Tarovik on 26.06.2021.
//

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream input("input.txt");
    cout << fixed << setprecision(3);
    if (input) {
        float f;
        while (input >> f) {
            cout << f << endl;
        }
    }
    
    return 0;
}
