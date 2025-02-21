#include <iostream>
using namespace std;

class Car {
private:
    string brand,model;
    double rentalPrice;
    bool available;
    int carID;
    double totalRevenue;

public:
    Car(): brand("Unknown"),model("Generic"),rentalPrice(0.0),available(true),carID(0),totalRevenue(0.0){}
    
    Car(string b,string m,double p,bool av, int id) : brand(b),model(m),rentalPrice(p),available(av),carID(id),totalRevenue(0.0){}
    
    Car(const Car &c) : brand(c.brand),model(c.model),rentalPrice(c.rentalPrice),available(c.available),carID(c.carID),totalRevenue(0.0){}
    
    ~Car() { cout << "Car with ID " << this->carID << " removed from memory." << endl; }

    double applyDiscount(int days) {
        if (days > 10){
            return 0.10;
            }
        else if (days > 5){
            return 0.05;
            }
        return 0.0;
    }
    void rentCar(int days) {
        if (!this->available) {
            cout << "Sorry!Car is not available for rent." << endl;
            return;
        }
    this->available = false;
        double discount = applyDiscount(days);
        double rentalCost = days * this->rentalPrice * (1 - discount);
        totalRevenue = totalRevenue+rentalCost;
        cout << "Car rented for " << days << " days. Total cost: " << rentalCost << "Rs" << endl;
    }
    void displayDetails() {
        cout << "Car ID: " << this->carID << "\nBrand: " << this->brand << "\nModel: " << this->model << "\nRental Price: " << this->rentalPrice  << "\nAvailability: " << (this->available ? "Yes" : "No") << "\nTotal Revenue: " << this->totalRevenue << "Rs" << "\n" << endl;
    }
        void modifyCar(string newBrand,string newModel,double newPrice) {
        this->brand = newBrand;
        this->model = newModel;
        this->rentalPrice = newPrice;
    }
};


int main() {
    Car car1("Buggati", "Cheyron", 9999.0, true, 777);
    Car copyCar(car1); 
    
    cout << "\nOriginal Car Details:" << endl;
    car1.displayDetails();
    
    cout << "\nCopied Car Details before modification:" << endl;
    copyCar.displayDetails();
    
    car1.modifyCar("Suzuki", "Mehran", 17.0);
    
    cout << "\nOriginal Car Details after modification:" << endl;
    car1.displayDetails();
    
    cout << "\nCopied Car Details after original modification:" << endl;
    copyCar.displayDetails();

    car1.rentCar(10);
    
    cout << "\nUpdated Car Details with Revenue:" << endl;
    car1.displayDetails();
    
    return 0;
}
