// Snippet 1 – Conceptual Encapsulation Example

class BankAccount {
private:
    int balance;   // sensitive data

public:
    void deposit(int amount) {
        if (amount > 0) {
            balance = balance + amount;
        }
    }
};

//---------------------------------------------------------------------------
// Snippet 2 – Simple Encapsulation Example


class BankAccount {
private:
    int balance;

public:
    void deposit(int amount) {
        balance = balance + amount;
    }
};


//---------------------------------------------------------------------------
// Snippet 3 – Practical Encapsulation Example

#include <iostream>
using namespace std;

class BankAccount {
private:
    int balance;

public:
    BankAccount() {
        balance = 0;
    }

    void deposit(int amount) {
        if (amount > 0) {
            balance = balance + amount;
        }
    }

    void showBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account;
    account.deposit(5000);
    account.showBalance();
    return 0;
}


//---------------------------------------------------------------------------
// Snippet 4 – Accessing Private Data (Compile-Time Error Demo)

class Demo {
private:
    int secret;

public:
    void setSecret(int s) { secret = s; }
};

int main() {
    Demo d;
    // d.secret = 10;  // ❌ compile-time error: 'secret' is private
    d.setSecret(10);    // ✅ allowed via public method
}


//---------------------------------------------------------------------------
// Snippet 5 – Read/Write Accessors with Validation

#include <iostream>
using namespace std;

class TemperatureSensor {
private:
    double celsius;

public:
    void setCelsius(double value) {
        if (value >= -273.15) {  // basic validation
            celsius = value;
        }
    }

    double getCelsius() const {
        return celsius;
    }
};

int main() {
    TemperatureSensor sensor;
    sensor.setCelsius(25.0);
    cout << "Temperature: " << sensor.getCelsius() << " °C" << endl;
    return 0;
}
//---------------------------------------------------------------------------
