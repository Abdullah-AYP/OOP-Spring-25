
#include <iostream>
using namespace std;

const int MAX_PRODUCTS = 100;

class Product {
private:
    string productID;
    string name;
    int quantity;

public:
    Product() {
        productID = "";
        name = "";
        quantity = 0;
    }
    Product(string id, string productN, int productQ) {
        productID = id;
        name = productN;
        quantity = productQ;
    }
    void displayInfo() {
        cout << "ID: " << productID << ", Name: " << name << ", Quantity: " << quantity;
    }
    void updateQuantity(int additional_quantity) {
        quantity += additional_quantity;
    }
    string getName(){
         return name; 
         }
    string getProductId() { 
        return productID;
         }
    int getQuantity() { 
        return quantity; 
        }
    bool hasId(string id) {
        return productID == id;
    }
};
class Warehouse {
private:
    string name;
    Product inventory[MAX_PRODUCTS];
    int productCount;

public:
    Warehouse(string warehouseN) {
        name = warehouseN;
        productCount = 0;
    }
    void addProduct(string productID, string name, int quantity) {
        for (int i = 0; i < productCount; i++) {
            if (inventory[i].hasId(productID)) {
                inventory[i].updateQuantity(quantity);
                cout << "Updated quantity of " << name << " (ID: " << productID << ")" << endl;
                return;
            }
        }
        if (productCount < MAX_PRODUCTS) {
            inventory[productCount++] = Product(productID, name, quantity);
            cout << "Added new product: " << name << " (ID: " << productID << ")" << endl;
        } else {
            cout << "Inventory is full, cannot add more products" << endl;
        }
    }
    Product* searchById(string productID) {
        for (int i = 0; i < productCount; i++) {
            if (inventory[i].hasId(productID)) {
                cout << "Product found: ";
                inventory[i].displayInfo();
                cout << endl;
                return &inventory[i];
            }
        }
        cout << "Product with ID " << productID << " not found" << endl;
        return nullptr;
    } 
    void displayInventory() {
        cout << "\n==== " << name << " Inventory ====" << endl;
        if (productCount == 0) {
            cout << "Inventory is empty" << endl;
            return;
        } 
        for (int i = 0; i < productCount - 1; i++) {
            for (int j = 0; j < productCount - i - 1; j++) {
                if (inventory[j].getName().compare(inventory[j + 1].getName()) > 0) {
                    swap(inventory[j], inventory[j + 1]);
                }
            }
        }
        for (int i = 0; i < productCount; i++) {
            inventory[i].displayInfo();
            cout << endl;
        }
        cout << endl;
    }
};
int main() {
   
    Warehouse warehouse("Imtiaz Supermarket");

    warehouse.addProduct("A1", "Sofa", 10);
    warehouse.addProduct("A2", "Laptop", 50);
    warehouse.addProduct("A3", "Meat", 1000);
    warehouse.addProduct("A4", "Table", 150);
    warehouse.addProduct("A5", "Smartphone", 500);

    warehouse.displayInventory();
    
    warehouse.searchById("A1");
    warehouse.searchById("A2");
    warehouse.searchById("A6"); 
    
    warehouse.addProduct("A3", "Meat", 500); 
    
    warehouse.displayInventory();
    
    return 0;
}
