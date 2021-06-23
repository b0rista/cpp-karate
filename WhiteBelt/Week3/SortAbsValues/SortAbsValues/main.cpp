//
//  main.cpp
//  SortAbsValues
//
//  Created by Boris Tarovik on 24.06.2021.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& i: v) {
        cin >> i;
    }
    
    sort(begin(v), end(v), [](int i, int j) {
        return abs(i) < abs(j);
    });
    
    for (auto i: v) {
        cout << i << ' ';
    }
    
    return 0;
}
