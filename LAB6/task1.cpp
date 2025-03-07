#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    float salary;
public:
    Employee(string n, float s) : name(n), salary(s) {}
     
    virtual void displayDetails() {
        cout << "Name: " << name << ", Salary: " << salary;
    }
};
class Manager : public Employee {
private:
    float bonus;
public:
    Manager(string n, float s, float b) : Employee(n, s), bonus(b) {}

    void displayDetails(){
        Employee::displayDetails(); 
        cout << ", Bonus: " << bonus << endl;
    }
};
int main() {
    Employee e("Fatima", 100000);
    Manager m("Abdullah", 500000, 50000);
    
    e.displayDetails();
    cout << endl;
    m.displayDetails();
    
    return 0;
}

