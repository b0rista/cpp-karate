//
//  main.cpp
//  BusStop3
//
//  Created by Boris Tarovik on 22.06.2021.
//

#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    int q;
    cin >> q;
    
    int number = 1;
    map<set<string>, int> pathNumber;
    
    while (q > 0) {
        int n;
        cin >> n;
        
        set<string> path;
        while (n > 0) {
            string stop;
            cin >> stop;
            path.insert(stop);
            --n;
        }
        
        if (pathNumber.count(path) > 0) {
            cout << "Already exists for " << pathNumber[path] << endl;
        }
        else {
            pathNumber[path] = number;
            cout << "New bus " << number << endl;
            ++number;
        }
        
        --q;
    }
    
    return 0;
}
