//
//  main.cpp
//  MeanTemperature
//
//  Created by Boris Tarovik on 19.06.2021.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    vector<int> tempArr(n);
    int meanTemp = 0;
    for (int& temp : tempArr) {
        cin >> temp;
        meanTemp += temp;
    }
    meanTemp /= n;
    
    vector<int> result;
    
    for (int i = 0; i < tempArr.size(); ++i) {
        if (tempArr[i] > meanTemp) {
            result.push_back(i);
        }
    }
    
    cout << result.size() << endl;
    for (auto i : result) {
        cout << i << ' ';
    }
    
    return 0;
}
