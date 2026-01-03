# Procedural Programming vs Object-Oriented Programming

Programming challenges can be approached with different mindsets. Two of the most common are **procedural programming** and **object-oriented programming (OOP)**. The distinction is less about *syntax* and more about *how you think* while designing software.

---

## Procedural Programming — *Step‑Based Thinking*

Procedural programs are written as a **sequence of instructions**. Functions operate on **shared data**, similar to workers using the same toolkit without formal ownership.

### Real‑World Analogy

Picture a small shop where:

* one person handles cash
* another writes receipts
* another manages inventory

Everyone can open the same cash drawer; no strict rules govern who changes what. This is fine while the shop is tiny, but errors spike as business grows.

### Procedural Example (C++)

```cpp
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
```

**Problems that appear as the codebase grows:**

* Data can be modified from anywhere.
* Bugs are hard to trace.
* Business rules are scattered across functions.
* Real‑world entities are difficult to model.
* Maintenance becomes risky.

---

## Object‑Oriented Programming — *Responsibility‑Based Thinking*

OOP flips the question from **“Which function should do this?”** to **“Which *object* is responsible for this?”**  Each object:

* **owns** its data
* **controls** all modifications to that data
* **represents** a real‑world entity

### Real‑World Analogy

Think of a modern bank system where:

* Every **BankAccount** keeps its own balance.
* No external code can touch that balance directly.
* All operations follow clearly defined rules.

### Same Problem Solved with OOP (C++)

```cpp
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
```

**Benefits this design brings:**

* Logic and data live together inside the class.
* Balance cannot be corrupted from outside.
* Code is easier to extend (add interest, transfer, etc.).
* The program mirrors real‑world behaviour.

---

## Core Difference in One Sentence

**Procedural programming** describes *how* things happen, while **object‑oriented programming** defines *who* is responsible.

---



### Next Up

Ready to explore OOP further? Jump to **Classes & Objects** to learn how to define, instantiate, and use classes effectively in modern C++.
