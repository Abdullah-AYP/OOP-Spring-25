#include <iostream>
#include <sstream>
using namespace std;

class DimensionMismatchException : public exception {
    string err;
public:
    DimensionMismatchException(int r1, int c1, int r2, int c2) {
        stringstream error;
        error << "Matrices must have same dimensions (" 
           << r1 << "x" << c1 << " vs " << r2 << "x" << c2 << ")";
        err = error.str();}
    const char* what() const noexcept override {
        return err.c_str();
    }
};
template<typename T, int MAX_R = 10, int MAX_C = 10>
class Matrix {
    int rows,columns;
    T data[MAX_R][MAX_C];
public:
    Matrix(int r = 0, int c = 0) : rows(r),columns(c){}

    void fill() {
        cout << "Enter elements (" << rows << "x" << columns << "):\n";
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                cin >> data[i][j];
    }
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns)
            throw DimensionMismatchException(rows,columns,other.rows,other.columns);

        Matrix result(rows,columns);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }
    void display() const {
        cout << "Matrix (" << rows << "x" << columns << "):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};
int main() {
    try {
        Matrix<int> A(1, 2), B(3, 4); 
        cout << "Matrix A:\n";
        A.fill();
        cout << "Matrix B:\n"; 
        B.fill();
        Matrix<int> C = A + B;
        C.display();
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}

