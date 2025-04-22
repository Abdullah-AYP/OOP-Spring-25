#include <iostream>
using namespace std;

class Patient {
protected:
    string name, id;
public:
    Patient(string n, string i) : name(n), id(i) {}
    virtual void displayTreatment() = 0;
    virtual double calculateCost() = 0;
};
class InPatient : public Patient {
public:
    InPatient(string n, string i) : Patient(n,i) {}
    void displayTreatment() {
        cout << "InPatient Treatment for " << name << ": Surgery & Recovery.\n";
    }
    double calculateCost() {
        return 5000.0;
    }
};
class OutPatient : public Patient {
public:
    OutPatient(string n, string i) : Patient(n,i) {}
    void displayTreatment() {
        cout << "OutPatient Treatment for " << name << ": Consultation & Medication.\n";
    }
    double calculateCost() {
        return 1500.0;
    }
};
int main() {
    Patient* p1 = new InPatient("Ali", "P101");
    Patient* p2 = new OutPatient("Sara", "P102");

    p1->displayTreatment();
    cout << "Cost: " << p1->calculateCost() << "\n\n";

    p2->displayTreatment();
    cout << "Cost: " << p2->calculateCost() << "\n";

    delete p1;
    delete p2;
    return 0;
}
