#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream large("large_log.txt");
    if (!large.is_open()) {
        cerr << "Error: Could not open large_log.txt" << endl;
        return 1;
    }
    char buffer[11] = {0};

    streampos pos1 = large.tellg();
    large.read(buffer, 10);
    cout << "First read: " << buffer << endl;
    cout << "Position before first read: " << pos1 << endl;
    cout << "Position after first read: " << large.tellg() << endl;

    streampos pos2 = large.tellg();
    large.read(buffer, 10);
    cout << "Second read: " << buffer << endl;
    cout << "Position before second read: " << pos2 << endl;
    cout << "Position after second read: " << large.tellg() << endl;

    large.close();
    return 0;
}
