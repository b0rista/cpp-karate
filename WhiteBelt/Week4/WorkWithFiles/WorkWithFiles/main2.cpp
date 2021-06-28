//
//  main2.cpp
//  WorkWithFiles
//
//  Created by Boris Tarovik on 26.06.2021.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream file("input.txt");
    if (file) {
        string s;
        while (getline(file, s)) {
            cout << s << endl;
        }
    }

    return 0;
}
