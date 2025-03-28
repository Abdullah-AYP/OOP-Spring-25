#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string contact;
    string address;

public:
    Person(string n, int a, string c, string add)
        : name(n), age(a), contact(c), address(add) {}

    virtual void displayInfo() const {
        cout << "Name: " << name << "\nAge: " << age << "\nContact: " << contact << "\nAddress: " << address << endl;
    }
    void updateInfo(string newContact, string newAddress) {
        contact = newContact;
        address = newAddress;
    }
};
class Patient : public Person {
    int patientID;
    string diagnosis;
    string assignedDoctor;

public:
    Patient(string n, int a, string c, int id, string d, string doc, string add)
        : Person(n, a, c, add), patientID(id), diagnosis(d), assignedDoctor(doc) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << "\nDiagnosis: " << diagnosis << "\nAssigned Doctor: " << assignedDoctor << endl;
    }
};
class Doctor : public Person {
    string specialization;
    float consultationFee;
    string patientList;

public:
    Doctor(string n, int a, string c, string sp, float f, string pa, string add)
        : Person(n, a, c, add), specialization(sp), consultationFee(f), patientList(pa) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << "\nConsultation Fee: " << consultationFee << "\nPatients: " << patientList << endl;
    }
};
class Nurse : public Person {
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string n, int a, string contact, string ward, string shift, string addr)
        : Person(n, a, contact, addr), assignedWard(ward), shiftTimings(shift) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << "\nShift Timings: " << shiftTimings << endl;
    }
};
class Administrator : public Person {
    string department;
    float salary;

public:
    Administrator(string n, int a, string contact, string dept, float sal, string addr)
        : Person(n, a, contact, addr), department(dept), salary(sal) {}

    void updateInfo(string newContact, string newAddress, float newSalary) {
        Person::updateInfo(newContact, newAddress);
        salary = newSalary;
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: " << salary << endl;
    }
};
int main() {
    Patient p1("Shaheen Afridi", 25, "0316-6969696", 100, "No Swing", "Dr. Amir", "House #69, Mardan, KPK");
    Doctor d1("Dr. Amir", 32, "0300-1111111", "Dismissing Virat Kohli", 6969.0, "Shaheen Afridi, Haris Rauf", "Clinic #1, Nazimabad, Karachi");
    Nurse n1("Mr. Junaid", 36, "0345-1019192", "PCB", "Day Shift", "House #2, Boat Basin, Karachi");
    Administrator a1("Muhammad Rizwan", 30, "0333-3333333", "Kaptaana", 100000.0, "Office #3, F11, Islamabad");

    cout << "Patient Information:\n";
    p1.displayInfo();
    cout << "\nDoctor Information:\n";
    d1.displayInfo();
    cout << "\nNurse Information:\n";
    n1.displayInfo();
    cout << "\nAdministrator Information:\n";
    a1.displayInfo();

    return 0;
}
