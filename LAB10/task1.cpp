#include <iostream>
#include <fstream>
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
        cout << "Read Line: " << line << endl;
    }
    vt.close();
    return 0;
}
