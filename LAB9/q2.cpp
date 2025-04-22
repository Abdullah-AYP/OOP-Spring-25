#include <iostream>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;
public:
    MenuItem(string dn, double p) : dishName(dn), price(p) {}
    virtual void showDetails() = 0;
    virtual void prepare() = 0;
};
class Appetizer : public MenuItem {
public:
    Appetizer(string dn, double p) : MenuItem(dn, p) {}
    void showDetails() {
        cout << "Appetizer: " << dishName << " - Rs " << price << "\n";
    }
    void prepare() {
        cout << "Preparing starter...\n";
    }
};
class MainCourse : public MenuItem {
public:
    MainCourse(string dn, double p) : MenuItem(dn, p) {}
    void showDetails() {
        cout << "Main Course: " << dishName << " - Rs " << price << "\n";
    }
    void prepare() {
        cout << "Cooking main course...\n";
    }
};
int main() {
    MenuItem* m1 = new Appetizer("One bite Samosa", 469);
    MenuItem* m2 = new MainCourse("Chicken Steak", 2269);

    m1->showDetails();
    m1->prepare();

    cout << "\n";

    m2->showDetails();
    m2->prepare();

    delete m1;
    delete m2;
    return 0;
}
