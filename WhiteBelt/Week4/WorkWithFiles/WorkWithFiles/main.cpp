//
//  main.cpp
//  WorkWithFiles
//
//  Created by Boris Tarovik on 26.06.2021.
//

#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream file("input.txt");
    ofstream outputFile("output.txt");
    if (file) {
        string s;
        while (getline(file, s)) {
            outputFile << s << endl;
        }
    }

    return 0;
}
