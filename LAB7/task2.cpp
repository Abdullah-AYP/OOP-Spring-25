#include <iostream>
using namespace std;

class Product {
protected:
    int productID;
    string productName;
    double price;
    int stockQuantity;

public:
    Product(int id, string n, double p, int sq = 0)
        : productID(id), productName(n), price(p), stockQuantity(sq) {}

    virtual void applyDiscount(double discount) {
        if (discount > 100) discount = 100; 
        price -= price * (discount / 100);
    }
    virtual void displayProductInfo() const {
        cout << "Product ID: " << productID << "\nName: " << productName
             << "\nPrice: Rs" << price << "\nStock: " << stockQuantity << "\n";
    }
    virtual double calculateTotalPrice(int quantity) const {
        return price * quantity;
    }
    friend ostream& operator<<(ostream& os, const Product& p) {
        p.displayProductInfo();
        return os;
    }
    Product operator+(const Product& other) {
        return Product(0, "Bulk Purchase", this->price + other.price);
    }
};
class Electronics : public Product {
    int warrantyPeriod;
    string brand;

public:
    Electronics(int id, string n, double p, int sq, int wp, string b)
        : Product(id, n, p, sq), warrantyPeriod(wp), brand(b) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Brand: " << brand << "\nWarranty: " << warrantyPeriod << " years\n";
    }
};
class Clothing : public Product {
    string size;
    string color;
    string fabricMaterial;

public:
    Clothing(int id, string n, double p, int sq, string s, string c, string f)
        : Product(id, n, p, sq), size(s), color(c), fabricMaterial(f) {}

    void applyDiscount(double discount) override {
        if (discount > 50) discount = 50;
        Product::applyDiscount(discount);
    }
    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Size: " << size << ", Color: " << color << ", Fabric: " << fabricMaterial << "\n";
    }
};
class FoodItem : public Product {
    string expirationDate;
    int calories;

public:
    FoodItem(int id, string n, double p, int sq, string exp, int cal)
        : Product(id, n, p, sq), expirationDate(exp), calories(cal) {}

    double calculateTotalPrice(int quantity) const override {
        double total = Product::calculateTotalPrice(quantity);
        if (quantity > 10) total *= 0.9;  
        return total;
    }
    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Expiration Date: " << expirationDate << ", Calories: " << calories << " kcal\n";
    }
};
class Book : public Product {
    string author, genre;

public:
    Book(int id, string name, double p, int stock, string a, string g)
        : Product(id, name, p, stock), author(a), genre(g) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Author: " << author << "\nGenre: " << genre << "\n";
    }
};
int main() {
    Electronics laptop(169, "Macbook Pro", 400000.0, 10, 1, "Apple");
    Clothing tshirt(269, "T-Shirt", 2000.0, 50, "M", "Black", "Silk");
    FoodItem apple(369, "Apple", 200.0, 100, "18-03-2025", 50);
    Book novel(469, "Mein Kampf", 4000.0, 30, "Adolf Hitler", "Realistic");

    cout << laptop << endl;
    cout << tshirt << endl;
    cout << apple << endl;
    cout << novel << endl;

    tshirt.applyDiscount(99);  
    cout << "Discounted T-Shirt Price:\n" << tshirt << endl;

    cout << "Total Price for 5 Apples: Rs" << apple.calculateTotalPrice(5) << "\n";

    Product bulkPurchase = novel + tshirt;
    cout << "Bulk Purchase Info:\n" << bulkPurchase << endl;

    return 0;
}
