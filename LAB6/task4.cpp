#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;
public:
    Account(int a, float b) : accountNumber(a), balance(b) {}  

    virtual void displayDetails() {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};
class SavingsAccount : public Account {
private:
    float interestRate;
public:
    SavingsAccount(int a, float b, float i) : Account(a, b), interestRate(i) {}  

    void displayDetails(){
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << ", Interest Rate: " << interestRate << "%" << endl;
    }
};
class CheckingAccount : public Account {
private:
    float overdraftLimit;
public:
    CheckingAccount(int a, float b, float o) : Account(a, b), overdraftLimit(o) {}  

    void displayDetails(){
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << ", Overdraft Limit: " << overdraftLimit << endl;
    }
};
int main() {
    SavingsAccount sa(1069, 99999, 2.5);
    CheckingAccount ca(1169, 88888, 10000);
    
    sa.displayDetails();
    ca.displayDetails();
    
    return 0;
}

