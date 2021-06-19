//
//  main.cpp
//  ReverseSequence2
//
//  Created by Boris Tarovik on 19.06.2021.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> reversed;
    for (int i = (int)v.size() - 1; i >= 0; --i) {
        reversed.push_back(v[i]);
    }
    return reversed;
}

int main(int argc, const char * argv[]) {
    auto x = Reversed({1, 5, 3, 2, 1, 6});
    return 0;
}
