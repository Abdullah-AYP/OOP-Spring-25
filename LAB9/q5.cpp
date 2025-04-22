#include <iostream>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight; 
public:
    Shipment(string n, double kg) : trackingNumber(n), weight(kg) {}
    virtual void estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
};
class AirFreight : public Shipment {
public:
    AirFreight(string n, double kg) : Shipment(n, kg) {}
    
    void estimateDeliveryTime() override {
        double time = (weight / 25.0) + 2; 
        cout << "Air Freight estimated delivery time: " << time << " hours.\n";
    }
    void showDetails() override {
        cout << "[Air Freight]\nTracking Number: " << trackingNumber
             << "\nWeight: " << weight << " kg\n";
    }
};
class GroundShipment : public Shipment {
public:
    GroundShipment(string n, double kg) : Shipment(n, kg) {}
    
    void estimateDeliveryTime() override {
        double time = (weight / 8.0) + 5; 
        cout << "Ground Shipment estimated delivery time: " << time << " hours.\n";
    }
    void showDetails() override {
        cout << "[Ground Shipment]\nTracking Number: " << trackingNumber
             << "\nWeight: " << weight << " kg\n";
    }
};
int main() {
    GroundShipment ground("ABC123", 72.5);
    AirFreight air("DEF456", 50.6);

    Shipment* shipment1 = &ground;
    Shipment* shipment2 = &air;

    cout << "=== Shipment Details ===\n";
    shipment1->showDetails();
    shipment1->estimateDeliveryTime();
    cout << "\n";
    shipment2->showDetails();
    shipment2->estimateDeliveryTime();

    return 0;
}
