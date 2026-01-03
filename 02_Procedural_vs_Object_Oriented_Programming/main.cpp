// Procedural Example (C++)

#include <iostream>
using namespace std;

int balance = 5000;               // shared, unprotected data

void deposit(int amount) {
    balance += amount;
}

void withdraw(int amount) {
    balance -= amount;            // no validation ➜ potential bug
}

int main() {
    deposit(1000);
    withdraw(3000);
    cout << "Balance: " << balance;
    return 0;
}



// Same Problem Solved with OOP (C++)

#include <iostream>
using namespace std;

class BankAccount {
private:
    int balance;                  // protected data

public:
    explicit BankAccount(int initial) : balance(initial) {}

    void deposit(int amount) {
        balance += amount;
    }

    void withdraw(int amount) {
        if (amount <= balance) {
            balance -= amount;    // guarded action
        }
    }

    void showBalance() const {
        cout << "Balance: " << balance;
    }
};

int main() {
    BankAccount account(5000);
    account.deposit(1000);
    account.withdraw(3000);
    account.showBalance();
    return 0;
}