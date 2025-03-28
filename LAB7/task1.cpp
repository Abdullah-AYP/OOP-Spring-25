#include <iostream>
using namespace std;

class Device {
protected:
    string deviceID;
    string deviceName;
    bool status;
public:
    Device(string id, string name) : deviceID(id), deviceName(name), status(false) {}
    virtual void turnOn() { status = true; }
    virtual void turnOff() { status = false; }
    virtual void displayInfo() const {
        cout << "Device: " << deviceName << " (" << (status ? "On" : "Off") << ")\n";
    }
};
class Light : public Device {
    int brightnessLevel;
    string colorMode;
public:
    Light(string id, string name, int brightness, string color)
        : Device(id, name), brightnessLevel(brightness), colorMode(color) {}
    void displayInfo() const override {
        Device::displayInfo();
        cout << "Brightness Level: " << brightnessLevel << ", Color Mode: " << colorMode << "\n";
    }
};
class Thermostat : public Device {
    float temperature;
    string mode;
    float targetTemperature;
public:
    Thermostat(string id, string name, float temp, string mode, float target)
        : Device(id, name), temperature(temp), mode(mode), targetTemperature(target) {}
    void displayInfo() const override {
        Device::displayInfo();
        cout << "Current Temperature: " << temperature << "C, Mode: " << mode 
             << ", Target: " << targetTemperature << "C\n";
    }
};
class SecurityCamera : public Device {
    string resolution;
    bool nightVisionEnabled;
public:
    SecurityCamera(string id, string name, string res, bool nightVision)
        : Device(id, name), resolution(res), nightVisionEnabled(nightVision) {}
    void turnOn() override {
        Device::turnOn();
        cout << "Security Camera is now recording.\n";
    }
    void displayInfo() const override {
        Device::displayInfo();
        cout << "Resolution: " << resolution << ", Night Vision: " << (nightVisionEnabled ? "Enabled" : "Disabled") << "\n";
    }
};
class SmartPlug : public Device {
    float powerConsumption;
    int timerSetting;
public:
    SmartPlug(string id, string name, float power, int timer)
        : Device(id, name), powerConsumption(power), timerSetting(timer) {}
    void turnOff() override {
        cout << "Power consumed before shutdown: " << powerConsumption << " kWh\n";
        Device::turnOff();
    }
    void displayInfo() const override {
        Device::displayInfo();
        cout << "Power Consumption: " << powerConsumption << " kWh, Timer: " << timerSetting << " mins\n";
    }
};
int main() {
    Light roomLight("L1", "Room Light", 75, "Warm White");
    Thermostat centralThermostat("T1", "Central Thermostat", 23.5, "Cooling", 25.5);
    SecurityCamera entryCamera("C1", "Entry Camera", "720p", true);
    SmartPlug appliancePlug("P1", "Appliance Plug", 1.2, 30);

    roomLight.displayInfo();
    cout << endl;

    centralThermostat.displayInfo();
    cout << endl;

    entryCamera.turnOn();
    entryCamera.displayInfo();
    cout << endl;
    
    appliancePlug.turnOff();
    appliancePlug.displayInfo();
    cout << endl;

    return 0;
}
