//
//  main.cpp
//  MoveStrings
//
//  Created by Boris Tarovik on 19.06.2021.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (auto w : source) {
        destination.push_back(w);
    }
    
    source.clear();
}

int main(int argc, const char * argv[]) {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    
    return 0;
}
