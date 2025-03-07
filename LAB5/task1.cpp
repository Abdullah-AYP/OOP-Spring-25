#include <iostream>
using namespace std;

class Apartment {
private:
    int id;
    char address[69];
    char* ownerName;  

public:
    Apartment(int i, const char* a, const char* o) {
        id = i;
        int j = 0;
        while (a[j] != '\0') {
            address[j] = a[j];
            j++;
        }
        address[j] = '\0';

        int length = 0;
        while (o[length] != '\0') {
            length++;
        }
        ownerName = new char[length + 1]; 
        for (int k = 0; k <= length; k++) {
            ownerName[k] = o[k];
        }
    }
    Apartment(const Apartment& other) {
        id = other.id;
        int j = 0;
        while (other.address[j] != '\0') {
            address[j] = other.address[j];
            j++;
        }
        address[j] = '\0';

        int length = 0;
        while (other.ownerName[length] != '\0') {
            length++;
        }
        ownerName = new char[length + 1];
        for (int k = 0; k <= length; k++) {
            ownerName[k] = other.ownerName[k];
        }
    }
    ~Apartment() {
        delete[] ownerName;
    }
    void display() {
        cout << "Apartment ID: " << id << "\nAddress: " << address << "\nOwner: " << ownerName << "\n";
    }
};
int main() {
    Apartment a1(69, "Tipu Sultan", "Ajmal Warraich");
    Apartment a2 = a1;  
    a1.display();
    a2.display();
    return 0;
}

