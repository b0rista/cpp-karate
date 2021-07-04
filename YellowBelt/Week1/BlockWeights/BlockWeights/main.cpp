//
//  main.cpp
//  BlockWeights
//
//  Created by Boris Tarovik on 01.07.2021.
//

#include <iostream>
#include <cstdint>
#include <limits>

using namespace std;

int main(int argc, const char * argv[]) {
    uint64_t resultingWeight = 0;
    
    uint64_t n, r;
    cin >> n >> r;
    for (uint64_t i = 0; i < n; ++i) {
        uint64_t w, h, d;
        cin >> w >> h >> d;
        resultingWeight += w * h * d * r;
    }
    
    cout << resultingWeight << endl;
    
    return 0;
}
