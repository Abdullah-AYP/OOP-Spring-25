#include <iostream>
using namespace std;

class AlarmSystem {
private:
    string security_level;

public:
    AlarmSystem(const string& level = "Medium") : security_level(level) {
        cout << "AlarmSystem created with " << security_level << " security level" << endl;
    }
    void displayInfo() {
        cout << "Security Level: " << security_level << endl;
    }
    void setSecurityLevel(const string& level) {
        security_level = level;
    }
    ~AlarmSystem() {
        cout << "AlarmSystem is being destroyed" << endl;
    }
};
class SmartHome {
private:
    string name;
    string location;
    AlarmSystem alarm_system;  

public:
    SmartHome(const string& homeN, const string& homeL, const string& securityLevel = "Medium")
        : name(homeN), location(homeL), alarm_system(securityLevel) {}

    void updateSecurity(const string& level) {
        alarm_system.setSecurityLevel(level);
        cout << "Alarm security level updated to " << level << endl;
    }
    void displayDetails() {
        cout << "Smart Home: " << name << endl;
        cout << "Location: " << location << endl;
        cout << "Alarm System: ";
        alarm_system.displayInfo();
        cout << endl;
    }
    ~SmartHome() {
        cout << "SmartHome '" << name << "' is being destroyed" << endl;
    }
};
int main() {
    SmartHome home1("Bilawal House", "Clifton");
    home1.displayDetails();
 
    home1.updateSecurity("High");
    home1.displayDetails();
    
    SmartHome home2("Lodi's House", "Gulshan-e-Iqbal", "Low");
    home2.displayDetails();

    cout << "Program ending....\n" << endl;
    return 0;
}

