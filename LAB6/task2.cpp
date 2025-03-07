#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    int speed;
public:
    Vehicle(string b, int s) : brand(b), speed(s) {}

    virtual void displayDetails() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }
};
class Car : public Vehicle {
protected:
    int seats;
public:
    Car(string b, int s, int seat) : Vehicle(b, s), seats(seat) {}

    void displayDetails(){
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h, Seats: " << seats << endl;
    }
};
class ElectricCar : public Car {
private:
    int batteryLife;
public:
    ElectricCar(string b, int s, int seat, int battery) : Car(b, s, seat), batteryLife(battery) {}

    void displayDetails(){
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h, Seats: " << seats  << ", Battery Life: " << batteryLife << " hours" << endl;
    }
};
int main() {
    ElectricCar tesla("Tesla", 269, 5, 4);
    tesla.displayDetails();

    return 0;
}
