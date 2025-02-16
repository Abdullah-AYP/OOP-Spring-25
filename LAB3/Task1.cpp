#include <iostream>
using namespace std;

class Wallet {
public:
    string ownerName;
    double totalBalance;
    double transactionAmounts[100]; 
    int transactionTypes[100]; 
    int transactionCount; 
    Wallet(string name) {
        ownerName = name;
        totalBalance = 0;
        transactionCount = 0;
    }
    void addMoney(double amount) {
        totalBalance = totalBalance+amount;
        if (transactionCount < 100) {
            transactionAmounts[transactionCount] = amount;
            transactionTypes[transactionCount] = 1; 
            transactionCount++;
        }
    }
    void spendMoney(double amount) {
        if (amount > totalBalance) {
            cout << "Insufficient balance!\n";
            return;
        }
        totalBalance = totalBalance-amount;
        if (transactionCount < 100) {
            transactionAmounts[transactionCount] = amount;
            transactionTypes[transactionCount] = -1; 
            transactionCount++;
        }
    }
    void displayTransactions() {
        cout << "Transaction History for " << ownerName << ":\n";
        for (int i = 0; i < transactionCount; i++) {
            if (transactionTypes[i] == 1) {
                cout << "Amount Added: " << transactionAmounts[i] << endl;
            } else {
                cout << "Amount Spent: " << transactionAmounts[i] << endl;
            }
        }
    }
};
int main() {
    Wallet myWallet("Saad");
    
    myWallet.addMoney(96);
    myWallet.spendMoney(69);
    myWallet.displayTransactions();

    return 0;
}
