# Access Specifiers and Encapsulation

Before studying access specifiers and encapsulation, it is important to understand where these concepts fit in Object‑Oriented Programming.

Object‑Oriented Programming is built on four main pillars. These pillars define why OOP is powerful and how it models real‑world systems.

---

## The Four Main Pillars of OOP

Object‑Oriented Programming is based on the following four fundamental principles:

* **Encapsulation**
* **Abstraction**
* **Inheritance**
* **Polymorphism**

Each pillar solves a specific problem in software design.

At this stage, we will focus on **Encapsulation**, because it is the first pillar that directly affects how data is protected and accessed.

---

## Why Encapsulation Is Needed

In real life, important information is never left open for everyone to change freely. There is always some form of control to ensure safety and correctness.

For example:

* your bank balance cannot be changed directly
* your personal documents cannot be edited by anyone
* critical systems allow access only through specific rules

The reason is simple: **uncontrolled access leads to mistakes, misuse, and instability**.

The same problem exists in programming. If data is freely accessible from everywhere, then:

* any part of the program can change it
* rules can be bypassed
* errors become hard to track

Encapsulation is used to solve this exact problem. It helps to:

* protect data from unwanted or accidental access
* control how and when data is modified
* hide internal details that should not concern the outside world
* make programs safer, more predictable, and easier to maintain

Without encapsulation, a program may work initially, but it becomes fragile as it grows.

---

## What Is Encapsulation?

Encapsulation is the OOP concept of bundling data **(attributes)** and methods **(functions)** into a single unit called a class while hiding the internal data from direct access and providing controlled access through public methods.

Encapsulation is both about bundling and hiding data, not just one.

In simple terms:

* data is kept inside the class
* outside code is **not** allowed to touch data directly
* interaction happens only through defined methods

Encapsulation does not mean hiding everything. It means **hiding what should not be accessed directly**, while still allowing safe and meaningful interaction. This balance between hiding and exposing is what makes encapsulation powerful.

---

## Real‑World Analogy of Encapsulation

Consider a bank account system.

In real life:

* you cannot directly change your account balance
* you must use valid actions like deposit or withdraw
* these actions follow rules (no negative deposits, no over‑withdrawal)

The internal balance is protected to ensure correctness.

In programming, encapsulation works in the same way:

* the account balance is treated as private data
* the deposit and withdraw functions are public methods
* all changes go through controlled logic

This prevents:

* invalid changes
* accidental misuse
* inconsistent state

That controlled boundary between data and access is exactly what encapsulation provides.

---

## Simple Conceptual Code Example

```cpp
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
```

In this example:

* `balance` is hidden and protected
* outside code cannot change it directly
* `deposit()` provides controlled access

This small example captures the core idea of encapsulation without unnecessary complexity.

---

## Role of Access Specifiers

An access specifier is a language mechanism in C++ that defines the level of visibility, accessibility, and control over the members of a class. It determines from where and by whom the data and behaviors of an object can be accessed.

More deeply, an access specifier acts as a protective boundary around a class. It separates:

Access specifiers define:

* who can access data
* from where it can be accessed

C++ provides three access specifiers:

* `public`
* `private`
* `protected`

At this stage, our focus is mainly on **public** and **private**.

### `private` Access Specifier

Members declared as **private**:

* cannot be accessed directly from outside the class
* are meant to be hidden and protected

This is where data protection begins.

### `public` Access Specifier

Members declared as **public**:

* can be accessed from outside the class
* are used to provide controlled interaction

Public members act as a safe interface.

---

## Simple Encapsulation Example (Conceptual)

```cpp
class BankAccount {
private:
    int balance;

public:
    void deposit(int amount) {
        balance = balance + amount;
    }
};
```

In this example:

* `balance` is **private** → cannot be changed directly
* `deposit()` is **public** → provides controlled access

This prevents misuse of sensitive data.

---

## Practical Encapsulation Example (Real‑World Linked)

```cpp
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
```

What this example demonstrates:

* `balance` is protected
* outside code cannot directly modify `balance`
* all changes go through controlled methods
* real‑world banking rules are respected

This is true encapsulation in practice.

---

## Additional Code Example 1 – Attempting to Access Private Data Directly

```cpp
class Demo {
private:
    int secret;

public:
    void setSecret(int s) { secret = s; }
};

int main() {
    Demo d;
    // d.secret = 10;  // ❌ compile‑time error: 'secret' is private
    d.setSecret(10);    // ✅ allowed via public method
}
```

This shows how the compiler blocks direct access to `secret`, forcing all interaction through controlled functions.

---

## Additional Code Example 2 – Combining Read & Write Accessors

```cpp
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
```

* `setCelsius()` validates input before writing.
* `getCelsius()` exposes data in a controlled, read‑only manner.

Together they illustrate encapsulation with both *write* and *read* access.

---

## Purpose of Encapsulation (Summary)

Encapsulation is used to:

* protect sensitive data
* reduce errors
* improve maintainability
* enforce rules
* model real‑world systems accurately

Without encapsulation:

* data becomes unsafe
* programs become fragile

---

## Important Conceptual Connection

* **Access Specifiers** → tools
* **Encapsulation** → principle

Access specifiers are used to achieve encapsulation.

---

## Why We Studied This Now

Encapsulation comes **before**:

1. inheritance
2. polymorphism
3. abstraction

Because **if data is not protected, advanced OOP concepts lose meaning**.
