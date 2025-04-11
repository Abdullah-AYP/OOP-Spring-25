#include <iostream>
using namespace std;
class Vector2D{
private:
    double x;
    double y;
public:
    Vector2D(double x, double y) : x(x), y(y) {}
    Vector2D operator+(const Vector2D& v) const {
        return Vector2D(x + v.x, y + v.y);
    }
    Vector2D operator-(const Vector2D& v) const {
        return Vector2D(x - v.x, y - v.y);
    }
    Vector2D operator*(double val) const {
        return Vector2D(x * val, y * val);
    }

    friend double dotProd(const Vector2D& v1, const Vector2D& v2);
    friend ostream& operator<<(ostream& os, const Vector2D& v);
};

double dotProd(const Vector2D& v1, const Vector2D& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}
ostream& operator<<(ostream& os, const Vector2D& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}
int main() {
    Vector2D v1(-6.9, 4.20);
    Vector2D v2(7.7, 2.20);
    cout << "Sum: " << v1 + v2 << endl;
    cout << "Difference: " << v1 - v2 << endl;
    cout << "Scaled v1: " << v1 * 3 << endl;
    cout << "Dot product: " << dotProd(v1, v2) << endl;
    return 0;
}
