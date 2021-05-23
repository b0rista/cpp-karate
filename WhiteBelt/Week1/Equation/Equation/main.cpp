//
//  main.cpp
//  Equation
//
//  Created by Boris Tarovik on 23.05.2021.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    double a, b, c;
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) {
            // only c not equal to 0
            // no solutions
        }
        else if (c == 0) {
            // only b not equal to 0
            cout << 0;
        }
        else {
            // b and c not equal to 0
            cout << -c/b;
        }
    }
    else if (b == 0) {
        if (c == 0) {
            // only a not equal to 0
            cout << 0;
        }
        else {
            // a and c not equal to 0
            if (a * c < 0) {
                double root = sqrt(-c/a);
                cout << root << ' ' << -root;
            }
        }
    }
    else if (c == 0) {
        // a and b not equal to 0
        cout << 0 << ' ' << -b/a;
    }
    else {
        // a, b and c not equal to 0
        double D = b * b - 4 * a * c;
        if (D > 0) {
            double sqrtD = sqrt(D);
            double x1 = (-b + sqrtD) / (2 * a);
            double x2 = (-b - sqrtD) / (2 * a);
            cout << x1 << ' ' << x2;
        }
        else if (D == 0) {
            double x = (-b + sqrt(D)) / (2 * a);
            cout << x;
        }
    }
}
