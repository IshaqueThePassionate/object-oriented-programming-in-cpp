# Const Objects in C++

**Definition:** A `const` object is an instance of a class that is initialized once and cannot be modified thereafter. The compiler treats it as read-only and strictly forbids calling any function that is not explicitly marked as `const`.

**Properties:**

* **Frozen State:** A const object is "frozen" upon creation; its internal data can never be changed.
* **Initialization Required:** You must provide values when creating the object because you cannot set them later.
* **Safe Reading:** A const object can only call member functions that are declared as `const` (read-only).
* **Write Protection:** If you attempt to call a function that modifies data (a non-const function), the compiler will generate an error to protect the object.

---

### Example 1: The Frozen Bank Account

**Concept:** Imagine a bank account that has been frozen due to suspicious activity.

* **Allowed:** You can **Check Balance** (Read-only).
* **Not Allowed:** You cannot **Withdraw Money** (Modification).

In C++, a `const` object acts exactly like this frozen account.

```cpp
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

```

---

### Example 2: Factory Default Settings

**Concept:** Think of the "Factory Settings" on your phone or in a video game.

* **Allowed:** You can **View** the default settings.
* **Not Allowed:** You cannot **Change** the factory defaults (they are permanent).

If you want to change settings, you create a *copy* (a normal object), but the original factory object remains `const`.

```cpp
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

```

### Summary of Differences

| Feature | Const Object (`const Student s1`) | Normal Object (`Student s2`) |
| --- | --- | --- |
| **Modification** | **Impossible.** Data is locked forever. | **Possible.** Can change data anytime. |
| **Function Calls** | Can ONLY call `const` functions (Read-Only). | Can call BOTH `const` and `non-const` functions. |
| **Real World Use** | Read-only files, Fixed Math Constants (PI), Security locks. | Normal variables, Counters, Active Users. |