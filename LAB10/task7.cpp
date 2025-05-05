#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream log("sensor_log.txt");

    streampos pos1 = log.tellp();
    log << "Sensor A: 27.3 C\n";
    cout << "Position before Sensor A: " << pos1 << " bytes\n";

    streampos pos2 = log.tellp();
    log << "Sensor B: 45% RH\n";
    cout << "Position before Sensor B: " << pos2 << " bytes\n";

    streampos pos3 = log.tellp();
    cout << "Final write position: " << pos3 << " bytes\n";

    log.close();
    return 0;
}
