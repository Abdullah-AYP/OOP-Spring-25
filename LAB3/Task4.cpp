#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand, model;
    double fuelCapacity, currentFuelLevel;
public:
    Car(string b, string m, double cap, double level) {
        brand = b;
        model = m;
        fuelCapacity = cap;
        currentFuelLevel = level;
    }
    void drive(double fuelUsed) {
        if (fuelUsed > currentFuelLevel) {
            cout << "Not enough fuel!" << endl;
        } else {
            currentFuelLevel = currentFuelLevel - fuelUsed;
            cout << "Fuel left: " << currentFuelLevel << " L" << endl;
        }
    }
    void refuel(double fuelAdded) {
        if (currentFuelLevel + fuelAdded > fuelCapacity) {
            cout << "Tank capacity reached!" << endl;
        } else {
            currentFuelLevel = currentFuelLevel + fuelAdded;
            cout << "Refueled successfully.Current fuel: " << currentFuelLevel << " L" << endl;
        }
    }
    void checkFuel() {
        cout << "Current fuel level: " << currentFuelLevel << " liters" << endl;
        if (currentFuelLevel < 5) {
            cout << "Warning: Low fuel!Refuel ASAP!" << endl;
        }
    }
};
int main() {
    Car myCar("Honda", "Civic", 47, 10);
    
    myCar.checkFuel();
    myCar.drive(6);
    myCar.checkFuel();
    myCar.refuel(20);
    myCar.checkFuel();
    
    return 0;
}
