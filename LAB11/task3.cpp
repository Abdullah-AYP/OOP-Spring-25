#include <iostream>
#include <exception>
using namespace std;

class InvalidTemperatureException : public exception {
public:
    const char* what() const noexcept override {
        return "Temperature is below zero!";
    }
};
template <typename T>
T convertToFahrenheit(T celsius) {
    if (celsius < -273.15)
        throw InvalidTemperatureException();
    return (celsius * 9/5) + 32;
}
int main() {
    try {
        double c = -274;  
        double f = convertToFahrenheit(c);
        cout << "Fahrenheit: " << f << endl;
    }
    catch (const InvalidTemperatureException& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}

