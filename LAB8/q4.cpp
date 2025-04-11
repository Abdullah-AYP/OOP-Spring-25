#include <iostream>
#include <string>
using namespace std;
class Car {
private:
    string mdl;
    double price;
public:
    Car(string m, double p) : mdl(m), price(p) {}
    friend class InventoryManager;
    friend void comparePrice(const Car& carA, const Car& carB);
};
class InventoryManager {
public:
    void displayDetails(const Car& car) {
        cout << "Model: " << car.mdl << endl;
        cout << "Price: " << car.price << endl;
    }
    void updatePrice(Car& car, double val) {
        car.price = val;
    }
};
void comparePrice(const Car& carA, const Car& carB) {
    if (carA.price > carB.price) {
        cout << carA.mdl << " costs more than " << carB.mdl << endl;
    }
    else if (carB.price > carA.price) {
        cout << carB.mdl << " costs more than " << carA.mdl << endl;
    } 
    else {
        cout << "They both cost the same" << endl;
    }
}
int main() {
    Car car1("La Ferrari", 3500000.0);
    Car car2("Buggati Veyron", 42000000.0);
    InventoryManager mgr;
    mgr.displayDetails(car1);
    mgr.displayDetails(car2);
    comparePrice(car1, car2);
    mgr.updatePrice(car1, 3800000.0);
    cout << "Updated Price:" << endl;
    mgr.displayDetails(car1);
    comparePrice(car1, car2);
    return 0;
}
