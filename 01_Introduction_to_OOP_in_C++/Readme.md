# Introduction to Object-Oriented Programming (OOP)

Object-Oriented Programming (OOP) is a programming approach in which software is designed by modeling **real‑world entities**. Instead of writing a program as a sequence of instructions, OOP organizes code around **objects**.

An object represents a real thing and contains:

* **data** (properties)
* **functions** (behavior)

A **class** is the blueprint used to create objects.

---

## Why Object‑Oriented Programming?

In traditional programming, data and functions are usually separate: functions operate on data that may be accessed from many places. This works for small programs, but as software grows:

* data becomes difficult to control
* logic spreads across the program
* maintaining and updating code becomes harder

OOP solves these problems by **grouping related data and functions together**.

---

## Real‑World Modeling

OOP is based on real‑world modeling. For example:

* A **Student** has a roll number and CGPA
* A **Car** has speed and fuel
* A **Bank Account** has a balance

In OOP:

* these real‑world things become **objects**
* their properties become **data members**
* their actions become **member functions**

This makes programs easier to understand and organize.

---

## Simple OOP Example

```cpp
#include <iostream>
using namespace std;

class Student {
public:
    int rollNo;
    float cgpa;

    void display() {
        cout << "Roll No: " << rollNo << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

int main() {
    Student s1;
    s1.rollNo = 101;
    s1.cgpa = 3.7;
    s1.display();
    return 0;
}
```

In this example:

* `Student` is a **class**
* `s1` is an **object**
* data and behavior are defined in one place

---

## Core Concepts in OOP

Object‑Oriented Programming is built on a few core ideas:

* **Class** – a blueprint
* **Object** – an instance of a class
* **Encapsulation** – binding data and functions together
* **Abstraction** – showing only necessary details
* **Inheritance** – reusing existing code
* **Polymorphism** – same interface, different behavior

These concepts will be discussed one by one in later sections.
