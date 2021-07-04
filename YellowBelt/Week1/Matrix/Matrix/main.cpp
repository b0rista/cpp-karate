//
//  main.cpp
//  Matrix
//
//  Created by Boris Tarovik on 30.06.2021.
//

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Matrix {
public:
    Matrix() {
        numRows = 0;
        numCols = 0;
    }
    
    Matrix(int numRows_, int numCols_) {
        if (numCols_ < 0 || numRows_ < 0) {
            throw out_of_range("");
        }
        numRows = numRows_;
        numCols = numCols_;
        values = vector<vector<int>>(numRows);
        for (auto& row: values) {
            row = vector<int>(numCols);
        }
    }
    
    void Reset(int newNumRows, int newNumCols) {
        if (newNumCols < 0 || newNumRows < 0) {
            throw out_of_range("");
        }
        numRows = newNumRows;
        numCols = newNumCols;
        values = vector<vector<int>>(numRows);
        for (auto& row: values) {
            row = vector<int>(numCols);
        }
    }
    
    int At(int row, int col) const {
        if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
            throw out_of_range("");
        }
        return values[row][col];
    }
    
    int& At(int row, int col) {
        if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
            throw out_of_range("");
        }
        return values[row][col];
    }
    
    int GetNumRows() const {
        return numRows;
    }
    
    int GetNumColumns() const {
        return numCols;
    }
    
private:
    int numRows;
    int numCols;
    vector<vector<int>> values;
};

istream& operator>>(istream& stream, Matrix& matrix) {
    int numRows;
    int numCols;
    stream >> numRows >> numCols;
    matrix.Reset(numRows, numCols);
    
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++ col) {
            stream >> matrix.At(row, col);
        }
    }
    
    return stream;
}

ostream& operator<<(ostream& stream, const Matrix& matrix) {
    stream << matrix.GetNumRows() << ' ' << matrix.GetNumColumns() << endl;
    for (int row = 0; row < matrix.GetNumRows(); ++row) {
        for (int col = 0; col < matrix.GetNumColumns(); ++ col) {
            stream << matrix.At(row, col);
            if (col != matrix.GetNumColumns() - 1) {
                stream << ' ';
            }
        }
        if (row != matrix.GetNumRows() - 1) {
            stream << endl;
        }
    }
    return stream;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
    if ((lhs.GetNumRows() == 0 || lhs.GetNumColumns() == 0)
        && (rhs.GetNumRows() == 0 || rhs.GetNumColumns() == 0)) {
        return true;
    }
    
    if (lhs.GetNumColumns() != rhs.GetNumColumns()
        || lhs.GetNumRows() != rhs.GetNumRows()) {
        return false;
    }
    
    for (int row = 0; row < lhs.GetNumRows(); ++row) {
        for (int col = 0; col < lhs.GetNumColumns(); ++ col) {
            if (lhs.At(row, col) != rhs.At(row, col)) {
                return false;
            }
        }
    }
    
    return true;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    if ((lhs.GetNumRows() == 0 || lhs.GetNumColumns() == 0)
        && (rhs.GetNumRows() == 0 || rhs.GetNumColumns() == 0)) {
        return Matrix();
    }
    
    if (lhs.GetNumColumns() != rhs.GetNumColumns()
        || lhs.GetNumRows() != rhs.GetNumRows()) {
        throw invalid_argument("");
    }
    
    Matrix result(lhs.GetNumRows(), lhs.GetNumColumns());
    for (int row = 0; row < lhs.GetNumRows(); ++row) {
        for (int col = 0; col < lhs.GetNumColumns(); ++ col) {
            result.At(row, col) = lhs.At(row, col) + rhs.At(row, col);
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    
    Matrix one;
      Matrix two;

      cin >> one >> two;
      cout << one + two << endl;
    return 0;
}
