#include <iostream>
#include <exception>
using namespace std;

class NegativeStockException : public exception {};
class OverCapacityException : public exception {};

template <typename T, int MAX_STOCK = 100>
class InventoryItem {
    T stock;
public:
    InventoryItem() : stock(0){}

    void setStock(T s) {
        if (s < 0)
            throw NegativeStockException();
        if (s > MAX_STOCK)
            throw OverCapacityException();
        stock = s;
    }
    void showStock() const {
        cout << "Current stock: " << stock << endl;
    }
};
int main() {
    InventoryItem<int> item;

    try {
        item.setStock(-1);  
    }
    catch (const NegativeStockException& e) {
        cout << "Caught NegativeStockException\n";
        cout << "Default error: " << e.what() << endl;
    }
    try {
        item.setStock(101);  
    }
    catch (const OverCapacityException& e) {
        cout << "Caught OverCapacityException\n";
        cout << "Default Error: " << e.what() << endl;
    }
    try {
        item.setStock(69);  
        item.showStock();
    }
    catch (...) {
        cout << "Caught some other exception.\n";
    }
    return 0;
}

