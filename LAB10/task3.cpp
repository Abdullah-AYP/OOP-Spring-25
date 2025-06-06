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

         int yearInt = stoi(year); 
        cout << "Vehicle ID: " << id << " | Year (int): " << yearInt << endl;
    }
    vt.close();
    return 0;
}
