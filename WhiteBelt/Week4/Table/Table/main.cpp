//
//  main.cpp
//  Table
//
//  Created by Boris Tarovik on 26.06.2021.
//

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream input("input.txt");
    
    if (input) {
        int nRow;
        int mCol;
        input >> nRow >> mCol;
        
        for (int row = 0; row < nRow; ++row) {
            if (row != 0) {
                cout << endl;
            }
            for (int col = 0; col < mCol; ++col) {
                if (col != 0) {
                    cout << ' ';
                    input.ignore(1);
                }
                int value;
                input >> value;
                cout << setw(10) << value;
            }
        }
        
    }
    
    return 0;
}
