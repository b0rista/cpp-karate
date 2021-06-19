//
//  main.cpp
//  ReverseSequence
//
//  Created by Boris Tarovik on 19.06.2021.
//

#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
    int leftIdx = 0;
    int rightIdx = (int)v.size() - 1;
    
    while (rightIdx > leftIdx) {
        int tmp = v[rightIdx];
        v[rightIdx] = v[leftIdx];
        v[leftIdx] = tmp;
        
        ++leftIdx;
        --rightIdx;
    }
}

int main(int argc, const char * argv[]) {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    return 0;
}
