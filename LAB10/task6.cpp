#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct InventoryItem {
    int itemID;
    char itemName[20];
};
int main() {
    InventoryItem i1 = {101, "WrenchSet"};
    ofstream out("inventory.dat", ios::binary);
    out.write((char*)&i1, sizeof(i1));
    out.close();
    cout << "Item written to inventory.dat\n";

    InventoryItem l1;
    ifstream in("inventory.dat", ios::binary);
    in.read((char*)&l1, sizeof(l1));
    in.close();

    cout << "Item read from file:\n";
    cout << "ID: " << l1.itemID << ", Name: " << l1.itemName << endl;

    return 0;
}
