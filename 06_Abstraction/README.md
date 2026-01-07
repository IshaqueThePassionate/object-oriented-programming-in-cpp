# Abstraction

Abstraction is the OOP concept of showing only essential features of a class or object to the user while hiding the internal implementation details. It focuses on what an object does, not how it does it.

While encapsulation focuses on **protecting data**, abstraction focuses on **simplifying usage**.

---

## Why Abstraction Is Needed

In real life, we use complex systems every day without knowing how they work internally.

For example:

* we drive a car without knowing engine mechanics
* we use a mobile phone without understanding its internal circuits
* we withdraw money from an ATM without knowing bank backend systems

If we were forced to understand internal details before using a system, **nothing would be practical to use**.

The same idea applies to software.

Abstraction is used to:

* hide unnecessary details
* reduce complexity
* allow users to focus only on **what they need to use**
* make systems easier and safer to use

---

## What Is Abstraction?

**Abstraction** means:

> **showing only essential features of an object and hiding the internal details**.

In simple words:

* the user knows **what an object does**
* the user does not need to know **how it does it**

Abstraction helps separate:

* *interface* (what is visible)
* *implementation* (how it works internally)

---

## Difference Between Encapsulation and Abstraction

Although they are related, they are **not the same**.

* **Encapsulation** → protects data from direct access
* **Abstraction** → hides unnecessary implementation details

Encapsulation is about **data safety**.
Abstraction is about **conceptual simplicity**.

Both work together to build clean and understandable systems.

---

## Real-World Analogy of Abstraction

Consider a **remote control**.

When you press a button:

* you do not know how signals are processed
* you do not know how hardware reacts

You only care that:

* pressing the button performs the expected action

In programming:

* the buttons represent **public methods**
* the hidden electronics represent **internal implementation**

That separation is abstraction.

---

## How Abstraction Appears in Classes

In Object-Oriented Programming, abstraction is achieved by:

* exposing **only necessary functions**
* hiding internal logic inside the class

The user of a class interacts with it through a **simple interface**.

---

## Simple Conceptual Code Example

```cpp
class Printer {
public:
    void print() {
        // User only sees this function
        // HOW printing happens is hidden
        // This is abstraction
    }
};
```

In this example:

* the user interacts only with `print()`
* internal printing logic is hidden
* complexity is abstracted away

This is abstraction at work.

---

## Abstraction Through Controlled Interface (More Clear Example)

```cpp
class Car {
public:
    void start() {
        // User calls start()
        // Internal engine logic is hidden
        // This method represents abstraction
        igniteEngine();
    }

private:
    void igniteEngine() {
        // Complex engine process
        // User never sees or calls this
    }
};
```

Here:

* `start()` is the **abstracted interface**
* `igniteEngine()` is **hidden implementation**
* the user only knows *what* happens, not *how*

This clearly demonstrates abstraction using a class.

---

## Abstraction Using Interfaces (Conceptual View)

Sometimes, abstraction is used to define **what an object must do**, not how it does it.

This is often done using **abstract classes**.

```cpp
class Shape {
public:
    virtual void draw() = 0; // pure virtual function
    // This forces derived classes to provide their own implementation
    // This is pure abstraction
};
```

Here:

* `Shape` defines **what** must be done (`draw`)
* it does not define **how** it is done
* implementation is left to derived classes

(Detailed usage will be covered later.)

---

## Purpose of Abstraction

Abstraction is used to:

* reduce complexity
* improve readability
* make systems easier to use
* allow changes without affecting users
* separate usage from implementation

Without abstraction, users would be forced to deal with unnecessary details.

---

## Important Idea to Remember

* Abstraction focuses on **what**, not **how**
* users interact with **interfaces**, not implementations
* abstraction makes large systems manageable

Encapsulation protects data.
Abstraction simplifies interaction.

---
