#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream data("data_records.txt");
    if (!data.is_open()) {
        cerr << "Error: Could not open data_records.txt" << endl;
        return 1;
    }
    int recordSize = 9;
    int recordNumber = 3;
    int offset = (recordNumber - 1) * recordSize;

    data.seekg(offset, ios::beg);

    string record;
    getline(data, record);
    cout << "Record " << recordNumber << ": " << record << endl;

    data.close();
    return 0;
}
