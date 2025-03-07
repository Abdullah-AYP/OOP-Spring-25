#include <iostream>
using namespace std;

class Device {
protected:
    int deviceID;
    bool status;
public:
    Device(int d, bool s) : deviceID(d), status(s) {}  

    virtual void displayDetails() {
        cout << "Device ID: " << deviceID << ", Status: ";
        if (status)
            cout << "On";
        else
            cout << "Off";
        cout << endl;
    }
};
class SmartPhone : virtual public Device {
private:
    float screenSize;
public:
    SmartPhone(int d, bool s, float sz) : Device(d, s), screenSize(sz) {}  

    void displayDetails() {
        cout << "Device ID: " << deviceID << ", Status: ";
        if (status)
            cout << "On";
        else
            cout << "Off";
        cout << ", Screen Size: " << screenSize << endl;
    }
};
class SmartWatch : virtual public Device {
protected:
    bool heartRateMonitor;
public:
    SmartWatch(int d, bool s, bool h) : Device(d, s), heartRateMonitor(h) {}  

    void displayDetails(){
        cout << "Device ID: " << deviceID << ", Status: ";
        if (status)
            cout << "On";
        else
            cout << "Off";

        cout << ", Heart Rate Monitor: ";
        if (heartRateMonitor)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
};
class SmartWearable : public SmartPhone, public SmartWatch {
private:
    int stepCounter;
public:
    SmartWearable(int d, bool s, float sz, bool h, int st) : Device(d, s), SmartPhone(d, s, sz), SmartWatch(d, s, h), stepCounter(st) {}

    void displayDetails(){
        SmartPhone::displayDetails();
        cout << "Heart Rate Monitor: ";
        if (heartRateMonitor)
            cout << "Yes";
        else
            cout << "No";
        cout << ", Step Counter: " << stepCounter << endl;
    }
};
int main() {
    SmartWearable sw(1, true, 2.0, true, 6969);
    sw.displayDetails();

    return 0;
}
