#include <iostream>
#include <cmath>
using namespace std;
class Complex {
private:
    double rl;
    double img;
public:
    Complex(double r, double i) {
        rl = r;
        img = i;
    }
    Complex operator+(const Complex& other) const {
        return Complex(rl + other.rl, img + other.img);
    }
    Complex operator-(const Complex& other) const {
        return Complex(rl - other.rl, img - other.img);
    }
    Complex operator*(const Complex& other) const {
        return Complex(rl * other.rl - img * other.img, rl * other.img + img * other.rl);
    }
    Complex operator/(const Complex& other) const {
        double r = (rl * other.rl + img * other.img) / other.rl * other.rl + other.img * other.img;
        double i = (img * other.rl - rl * other.img) / other.rl * other.rl + other.img * other.img;
        return Complex(r, i);
    }
    friend double magnitude(const Complex& c);
    friend ostream& operator<<(ostream& out, const Complex& c) {
        if(c.img >= 0){
        out << "" << c.rl << " + " << fabs(c.img) << "i";
        }
        else{
            out << "" << c.rl << " - " << fabs(c.img) << "i";
        }
        return out;
    }
};
double magnitude(const Complex& c) {
    return sqrt(c.rl * c.rl + c.img * c.img);
}
int main() {
    Complex comp1(75, 32);
    Complex comp2(69, -2);
    cout << "complex 1 + complex 2 + b = " << comp1 + comp2 << endl;
    cout << "complex 1 - complex 2 + b = " << comp1 - comp2 << endl;
    cout << "complex 1 * complex 2 + b = " << comp1 * comp2 << endl;
    cout << "complex 1 / complex 2 + b = " << comp1 / comp2 << endl;
    cout << "Magnitude of complex 1: " << magnitude(comp1) << endl;
    cout << "Magnitude of complex 2: " << magnitude(comp2) << endl;
    return 0;
}
