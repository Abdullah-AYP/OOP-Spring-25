#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream vt("vehicles.txt");
    if (!vt.is_open()) {
        cerr << "Error: Could not open vehicles.txt" << endl;
        return 1;
    }
    string line;
    while (getline(vt,line)) {
        if (line.empty() || line[0] == '/')
         continue; 

        stringstream ss(line);
        string type,id,name,year,extraData,certification;

        getline(ss,type,',');
        getline(ss,id,',');
        getline(ss,name,',');
        getline(ss,year,',');
        getline(ss,extraData,',');
        getline(ss,certification);

        cout << "Vehicle Type: " << type << " | Extra Data: " << extraData << endl;

    if (type == "AutonomousCar") {
            size_t pos = extraData.find(":");
            if (pos != string::npos) {
                string sw = extraData.substr(pos + 1);
                cout << "Software Version: " << sw << endl;
            }
        } else if (type == "ElectricVehicle") {
            size_t pos = extraData.find(":");
            if (pos != string::npos) {
                string bc = extraData.substr(pos + 1);
                cout << "Battery Capacity: " << bc << endl;
            }
        }
     if (type == "HybridTruck") {
            size_t cSt = extraData.find(":") + 1;
            size_t pPos = extraData.find("|");
            size_t bSt = extraData.find("Battery:") + 8;

            if (cSt != string::npos && pPos != string::npos && bSt != string::npos) {
                string cStr = extraData.substr(cSt, pPos - cSt);
                string bStr = extraData.substr(bSt);

                int cargo = stoi(cStr);
                int battery = stoi(bStr);

                cout << "Cargo Capacity (int): " << cargo << endl;
                cout << "Battery Capacity (int): " << battery << endl;
            }
    }
    vt.close();
    return 0;
}

