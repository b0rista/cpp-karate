//
//  main.cpp
//  AvgTemp2
//
//  Created by Boris Tarovik on 01.07.2021.
//

#include <iostream>
#include <cstdint>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int64_t sum = 0;
    vector<int64_t> v(n);
    for (auto& i: v) {
        cin >> i;
        sum += i;
    }
    
    sum /= n;
    size_t countMoreThanAvg = count_if(begin(v), end(v), [sum](int64_t x){
        return x > sum;
    });
    cout << countMoreThanAvg << endl;
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] > sum) {
            cout << i << ' ';
        }
    }
    
    return 0;
}
