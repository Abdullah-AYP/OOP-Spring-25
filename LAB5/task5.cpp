#include <iostream>
using namespace std;

class Hospital;

class Doctor {
private:
    string name;
    string specialization;
    int experience;
    Hospital* hospitals[10];
    int hospitalCount;

public:
    Doctor(string docN, string docS, int docE) {
        name = docN;
        specialization = docS;
        experience = docE;
        hospitalCount = 0;
    }
    void assignToHospital(Hospital* hospital);
    void displayInfo();
    
    string getName(){ 
        return name;
        }
    string getSpecialization(){ 
        return specialization;
        }
    int getExperience(){ 
        return experience; 
        }
};
class Hospital {
private:
    string name;
    string location;
    Doctor* doctors[100];
    int doctorCount;

public:
    Hospital(string hospN, string hospL) {
        name = hospN;
        location = hospL;
        doctorCount = 0;
    }
    void addDoctor(Doctor* doctor) {
        for (int i = 0; i < doctorCount; i++) {
            if (doctors[i] == doctor) {
                return; 
            }
        }
        if (doctorCount < 100) {
            doctors[doctorCount++] = doctor;
        }
    }
    void displayDetails() {
        cout << "Hospital: " << name << endl;
        cout << "Location: " << location << endl;
        cout << "Doctors currently working here:" << endl;
        
        if (doctorCount == 0) {
            cout << "  No doctors currently assigned" << endl;
        } else {
            for (int i = 0; i < doctorCount; i++) {
                cout << "  - Dr. " << doctors[i]->getName() << " (" 
                     << doctors[i]->getSpecialization() << ")" << endl;
            }
        }
        cout << endl;
    }
    string getName() { return name; }
};
void Doctor::assignToHospital(Hospital* hospital) {
    for (int i = 0; i < hospitalCount; i++) {
        if (hospitals[i] == hospital) {
            return; 
        }
    }
    if (hospitalCount < 10) {
        hospitals[hospitalCount++] = hospital;
        hospital->addDoctor(this);
    }
}
void Doctor::displayInfo() {
    cout << "Dr. " << name << ", " << specialization << ", " 
         << experience << " years of experience" << endl;
    cout << "Working at hospitals:" << endl;
    
    if (hospitalCount == 0) {
        cout << "  Not assigned to any hospital yet" << endl;
    } else {
        for (int i = 0; i < hospitalCount; i++) {
            cout << "  - " << hospitals[i]->getName() << endl;
        }
    }
    cout << endl;
}
int main() {
    Doctor drAbdullah("Abdullah", "Cardiology", 15);
    Doctor drShimaz("Shimaz", "Neurology", 18);
    Doctor drFatima("Fatima", "Pediatrics", 12);
    
    Hospital liaquat("Liaquat National", "Stadium Road");
    Hospital agakhan("AgaKhan", "Stadium Road");
    
    drAbdullah.assignToHospital(&liaquat);
    drAbdullah.assignToHospital(&agakhan);  
    drShimaz.assignToHospital(&agakhan);
    drFatima.assignToHospital(&liaquat);

    cout << "==== DOCTOR INFORMATION ====" << endl;
    drAbdullah.displayInfo();
    drShimaz.displayInfo();
    drFatima.displayInfo();
    
    cout << "==== HOSPITAL DETAILS ====" << endl;
    liaquat.displayDetails();
    agakhan.displayDetails();
    
    return 0;
}
