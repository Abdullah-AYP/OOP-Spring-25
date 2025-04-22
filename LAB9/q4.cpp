#include <iostream>
using namespace std;

class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
};
class Thermometer : public WeatherSensor {
    float temperature;
public:
    void readData() override {
        temperature = 29.8;  
        cout << "Thermometer: Measuring ambient temperature...\n";
    }
    void displayReport() override {
        cout << "Current Temperature: " << temperature << " °C\n";
    }
};
class Barometer : public WeatherSensor {
    float airPressure;
public:
    void readData() override {
        airPressure = 1015.6;  
        cout << "Barometer: Checking atmospheric pressure...\n";
    }
    void displayReport() override {
        cout << "Current Pressure: " << airPressure << " hPa\n";
    }
};
int main() {
    Thermometer thermometer;
    Barometer barometer;

    WeatherSensor* sensor1 = &thermometer;
    WeatherSensor* sensor2 = &barometer;

    sensor1->readData();
    sensor1->displayReport();
    cout << endl;

    sensor2->readData();
    sensor2->displayReport();

    return 0;
}
