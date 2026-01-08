#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    // Constructor
    BankAccount(double initialBalance) : balance(initialBalance) {}

    // 1. NON-CONST Function (Action/Writer)
    // This function CHANGES the balance.
    // A frozen (const) account CANNOT use this.
    void withdraw(double amount) {
        balance = balance - amount;
        cout << "Withdrawn: " << amount << endl;
    }

    // 2. CONST Function (Info/Reader)
    // This function ONLY SHOWS the balance.
    // It promises NOT to change anything, so a frozen account CAN use this.
    void checkBalance() const {
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    // SCENARIO: A "Frozen" Account (Const Object)
    const BankAccount frozenAcc(5000.00);

    cout << "--- Bank System ---" << endl;

    // ✅ ALLOWED: Just checking info
    frozenAcc.checkBalance();

    // ❌ ERROR: Trying to modify a frozen account
    // frozenAcc.withdraw(500.00); // <-- This line will cause a Compiler Error!
    // Error message: "passing 'const BankAccount' as 'this' argument discards qualifiers"

    return 0;
}

//-----------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

class GameSettings {
private:
    int volume;
    int brightness;

public:
    // Constructor using Member Initializer List
    GameSettings(int v, int b) : volume(v), brightness(b) {}

    // 1. NON-CONST Function (Modifier)
    // Allows changing volume.
    void setVolume(int v) {
        volume = v;
    }

    // 2. CONST Function (Viewer)
    // Just displays the settings. Safe for const objects.
    void display() const {
        cout << "Volume: " << volume << "% | Brightness: " << brightness << "%" << endl;
    }
};

int main() {
    // SCENARIO: Factory Defaults (Must remain permanent)
    const GameSettings factoryDefaults(50, 70);

    // SCENARIO: User Settings (Can be changed)
    GameSettings userSettings(50, 70);

    cout << "--- Game Configuration ---" << endl;

    // 1. Dealing with Factory Defaults (Read-Only)
    cout << "[Factory Defaults] ";
    factoryDefaults.display();      // ✅ OK: display() is const
    // factoryDefaults.setVolume(90); // ❌ ERROR: Cannot change factory defaults!

    // 2. Dealing with User Settings (Modifiable)
    cout << "\n[User Update] Changing volume..." << endl;
    userSettings.setVolume(100);    // ✅ OK: userSettings is NOT const
    
    cout << "[User Settings]    ";
    userSettings.display();

    return 0;
}
