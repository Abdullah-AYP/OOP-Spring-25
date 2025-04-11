#include <iostream>
using namespace std;
class Matrix2x2 {
private:
    int a, b, c, d;
public:
    Matrix2x2(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
    Matrix2x2 operator+(const Matrix2x2& m) const {
        return Matrix2x2(a + m.a, b + m.b, c + m.c, d + m.d);
    }
    Matrix2x2 operator-(const Matrix2x2& m) const {
        return Matrix2x2(a - m.a, b - m.b, c - m.c, d - m.d);
    }
    Matrix2x2 operator*(const Matrix2x2& m) const {
        return Matrix2x2(a * m.a + b * m.c, a * m.b + b * m.d, c * m.a + d * m.c, c * m.b + d * m.d);
    }
    friend class MatrixHelper;
    friend int determinant(const Matrix2x2& m);
    friend ostream& operator<<(ostream& os, const Matrix2x2& m);
};
class MatrixHelper {
public:
    void updateElement(Matrix2x2& m, int r, int c, int val) {
        if (r== 0 && c == 0) m.a = val;
        else if (r == 1 && c == 0) m.c = val;
        else if (r == 1 && c == 1) m.d = val;
        else if (r == 0 && c == 1) m.b = val;
    }
};
int determinant(const Matrix2x2& m) {
    return m.a * m.d - m.b * m.c;
}
ostream& operator<<(ostream& os, const Matrix2x2& m) {
    os << "[ " << m.a << " " << m.b << " ]\n";
    os << "[ " << m.c << " " << m.d << " ]";
    return os;
}
int main() {
    Matrix2x2 m1(5, 3, 3, 4);
    Matrix2x2 m2(8, -3, 0, -10);
    cout << "Matrix 1:\n" << m1 << endl;
    cout << "Matrix 2:\n" << m2 << endl;
    cout << "Sum:\n" << m1 + m2 << "\n\n";
    cout << "Difference:\n" << m1 - m2 << "\n\n";
    cout << "Product:\n" << m1 * m2 << "\n\n";
    cout << "Determinant of m1: " << determinant(m1) << endl;
    MatrixHelper m;
    m.updateElement(m1, 2, 2, 69);
    cout << "Updated m1:\n" << m1 << endl;
    return 0;
}
