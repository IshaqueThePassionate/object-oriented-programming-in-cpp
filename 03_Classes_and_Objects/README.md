# Classes and Objects

## Why We Study Classes and Objects

Object‑Oriented Programming is studied because real‑world problems are not made of random data or isolated steps. In real life, we think in terms of **things** such as students, cars, and bank accounts. Each of these things has its own identity and information. Classes and objects allow us to represent these real‑world entities inside a program in an organized and meaningful way.

Instead of treating data as scattered values, OOP groups related information together and gives it a clear structure. This makes programs easier to understand, design, and maintain as they grow.

---

## Modeling Real‑World Entities

Modeling a real‑world entity means identifying:

* what kind of entity it is
* what information belongs to it

For example, even before any real student exists, we already know that a student has a roll number and a CGPA. This understanding exists at a conceptual level. In programming, this conceptual understanding is represented using a **class**.

At this stage, we are not interested in values or behavior. We are only defining **what the entity is**.

---

## What Is a Class?

A **class** is a **user‑defined data type**.
It is created by the programmer to represent a real‑world concept that is not available as a built‑in type.

A class describes:

* the structure of an entity
* the kind of data the entity will contain

A class does **not** represent a real object by itself. It only defines **how a real object should look**.

In simple words, a class answers the question:
**“What is this entity?”**

---

## Class as a Concept

Before talking about real students, we already understand the concept of a student. This concept exists independently of actual students. In programming, this abstract idea is what a class represents.

So:

* the idea of a student → class
* a real student → object

This separation between concept and reality is fundamental in Object‑Oriented Programming.

---

## Basic Class Syntax

The basic syntax of a class looks like this:

```cpp
class Student {
    int rollNo;
    float cgpa;
};
```

This code means:

* `Student` is a new user‑defined type
* any entity of type `Student` will have:

  * a roll number
  * a CGPA

At this point:

* no memory is allocated
* no real student exists
* only the **structure** has been defined

This is why a class is often described as a **blueprint**.

---

## Real‑World Analogy for a Class

A useful analogy for a class is a **blank form**.
The form defines which fields exist, but until it is filled, it does not represent a real person.

Similarly:

* a class defines structure
* it does not contain real data

---

## What Is an Object? (Conceptual Understanding)

An **object** is a **real instance** created from a class.
If a class defines what a student is, then an object represents an actual student.

At this stage, it is enough to understand that:

* a class describes
* an object represents

We are not yet concerned with creating or accessing objects. That will be covered later.

---

## Real‑World Analogy for an Object

Continuing the form example:

* a filled form represents a real person
* it contains actual information

In the same way:

* a class provides structure
* an object contains real data based on that structure

---

## Relationship Between Class and Object

The relationship between class and object is very important:

* a class defines the concept
* an object represents the reality
* a class can exist without objects
* objects cannot exist without a class

This relationship allows programs to model the real world accurately.

---

## Key Idea to Remember

* **Class** → description or type
* **Object** → real instance of that type

For now, our focus is only on understanding these ideas clearly. Practical usage will come in later topics.

---

### Code Example: Creating an Object

```cpp
#include <iostream>
using namespace std;

class Student {
public:
    int rollNo;
    float cgpa;
};

int main() {
    Student student1;      // object creation
    student1.rollNo = 101;
    student1.cgpa   = 3.8;

    cout << "Roll No: " << student1.rollNo << "\n";
    cout << "CGPA: " << student1.cgpa << endl;
    return 0;
}
```
Here is the detailed explanation regarding Memory Allocation, the Class, and the Constructor, formatted separately as requested.

---

## When is Memory Allocated?

**Memory is allocated when the Object is created.**

### 1. Does a Class take memory?

**No.**
A Class is just a **blueprint** or a template (like a map of a house). Writing `class Student { ... };` does not occupy any memory in the RAM. It just tells the compiler how the data structure looks.

### 2. When does Memory Allocation happen?

Memory is allocated exactly when you create an instance (an **Object**) of the class.

* **Statement:** `Student s1;`
* **Action:** The computer finds empty space in the memory (RAM) equal to the size of the variables inside the class and reserves it for `s1`.

### 3. When is the Constructor called?

The Constructor is called **immediately after** the memory has been allocated.
It is impossible to run a constructor without memory because the constructor's job is to put values *into* that memory.

### The Exact Sequence of Events

When you write this line of code:

```cpp
Student s1;

```

The computer performs these steps in order:

1. **Memory Allocation:** The system allocates space in RAM for `s1`.
2. **Constructor Call:** The system calls `Student()` to initialize that allocated memory space.
3. **Object Ready:** The object is now ready to be used.

### Real-Life Analogy

* **Class:** The **Architect's Plan** (Map) of a house. (Occupies no land).
* **Object Creation (Memory Allocation):** **Building the house** on a plot of land. (Now it occupies space).
* **Constructor:** **Interior Decoration** (Setting up furniture). You can only put furniture (values) inside the house *after* the house (memory) is built.
---
