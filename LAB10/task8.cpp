#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream config("config.txt", ios::in | ios::out);
    if (!config.is_open()) {
        cerr << "Error: Could not open config.txt" << endl;
        return 1;
    }
    config.seekp(5);
    config.write("babar", 5); 

    config.seekg(0);
    string updated;
    getline(config,updated);
    cout << "New Config Line: " << updated << endl;

    config.close();
    return 0;
}

