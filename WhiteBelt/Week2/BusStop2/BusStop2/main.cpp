//
//  main.cpp
//  BusStop2
//
//  Created by Boris Tarovik on 22.06.2021.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<vector<string>, int> pathNumber;

int main(int argc, const char * argv[]) {
    int q;
    cin >> q;
    
    int number = 1;
    
    while (q > 0) {
        int i;
        cin >> i;
        
        vector<string> path;
        while (i > 0) {
            string stop;
            cin >> stop;
            path.push_back(stop);
            --i;
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
