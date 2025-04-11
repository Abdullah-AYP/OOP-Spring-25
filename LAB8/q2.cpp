#include <iostream>
using namespace std;
class Account{
private:
    int accNum;
    double bal;
public:
    Account(int accNum, double bal) : accNum(accNum), bal(bal) {}
    friend class Manager;
    friend void transferFunds(Account& from, Account& to, double amt);
};
class Manager {
public:
    void deposit(Account& acc, double amount) {
        acc.bal += amount;
    }
    void displayAccountDetails(const Account& acc) {
        cout << "Account Number: " << acc.accNum << endl;
        cout << "Balance: " << acc.bal << endl;
    }
    void transferFunds(Account& from, Account& to, double amount) {
        if (from.bal >= amount) {
            to.bal += amount;
            from.bal -= amount;
            cout << "Successfully Transfered funds." << endl;
        } 
        else {
            cout << "Transfer failed" << endl;
        }
    }
    void withdraw(Account& acc, double amount){
        if (acc.bal>= amount) {
            acc.bal -= amount;
        } 
        else {
            cout << "Not enough funds!" << endl;
        }
    }
};
int main() {
    Account accA(420, 120.0);
    Account accB(69, 670.0);
    Manager mgr;
    mgr.displayAccountDetails(accA);
    mgr.displayAccountDetails(accB);
    mgr.deposit(accA, 555.0);
    mgr.withdraw(accB, 699.0);
    mgr.transferFunds(accA, accB, 788.0);
    mgr.displayAccountDetails(accA);
    mgr.displayAccountDetails(accB);
    return 0;
}
