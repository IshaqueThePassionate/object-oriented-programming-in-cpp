# Module 2: The Anatomy of a Class (Data & Functions)

In Module 1, we learned that a class is a blueprint. Now, we need to understand **what actually exists inside that blueprint**.

Every real-world entity has two things:

1. **Information** (What it knows).
2. **Actions** (What it does).

In Object-Oriented Programming (OOP), we map these directly to:

1. **Data Members** (Information).
2. **Member Functions** (Actions).

---

## 1. What Are Data Members? (The State)

**Definition:** Data members are variables that belong to a class. They represent the **state** or information of an object.

In real life, when we talk about a student, we automatically think about their `roll number` or `CGPA`. In programming, these specific pieces of information are stored as data members.

**Key Properties:**

* **Structure:** Data members only define the structure; they do not hold real values until an object is created.
* **Memory:** Each object gets its **own unique copy** of data members. If you have 2 students, you have 2 separate roll numbers in memory.

**Basic Structure:**

```cpp
class Student {
    // These are Data Members
    int rollNo; 
    float cgpa;
};

```

---

## 2. What Are Member Functions? (The Behavior)

**Definition:** Member functions are functions that belong to a class. They define **what an object can do**.

In real life, a student can "display records" or "take an exam". These actions are written as functions inside the class.

**Key Difference from Normal Functions:**
A normal function works on arguments passed to it. A **Member Function** works directly on the **Data Members** of the object that called it.

---

## 3. Defining Member Functions: The Two Ways

This is where things get technical. In C++, there are two distinct ways to define these functions. The difference affects how the computer handles the code.

### Method A: Defining INSIDE the Class (Implicit Inline)

In this method, the function body is written directly inside the class. This is best for small, simple functions.

**Technical Term:** **Inline Function**.

* **How it works:** The compiler "copies and pastes" the function code logic wherever it is called, instead of jumping to a separate memory location.
* **Pros:** Very fast for small tasks.
* **Cons:** Can increase file size if the function is large.

**Code Example (Inside Definition):**

```cpp
#include <iostream>
using namespace std;

class Student {
public:
    int rollNo;

    // DEFINITION INSIDE THE CLASS
    // The code is written directly here.
    void setRollNo(int r) {
        rollNo = r;
    }
    
    void display() {
        cout << "Roll No: " << rollNo << endl;
    }
};

int main() {
    Student s1;
    s1.setRollNo(101); // The compiler "pastes" the code here (Inline)
    s1.display();
    return 0;
}

```

---

### Method B: Defining OUTSIDE the Class (Using Scope Resolution)

This is the professional standard for larger programs. We split the function into two parts:

1. **Declaration (Prototype):** Inside the class (The Promise).
2. **Definition (Implementation):** Outside the class (The Actual Code).

**Technical Term:** **Standard Function Call**.

* **How it works:** The program "jumps" to the memory address of the function, executes it, and returns.

**The Scope Resolution Operator (`::`)**
To define a function outside, we need the Scope Resolution Operator `::`.
It acts like a connector. If you just write `void display()`, the computer thinks it's a normal function. By writing `void Student::display()`, you tell the computer: *"This function belongs to the Student class."*

**Code Example (Outside Definition):**

```cpp
#include <iostream>
using namespace std;

class Student {
public:
    int rollNo;

    // 1. DECLARATION ONLY
    // We only write the prototype here. Note the semicolon ';'
    void setRollNo(int r);
    void display();
};

// 2. DEFINITION OUTSIDE
// We use 'Student::' to connect this code to the Student class.

// Syntax: ReturnType ClassName::FunctionName(Parameters)
void Student::setRollNo(int r) {
    rollNo = r;
}

void Student::display() {
    cout << "Roll No: " << rollNo << endl;
}

int main() {
    Student s1;
    s1.setRollNo(101); // The program "jumps" to the function definition
    s1.display();
    return 0;
}

```
<br>

---



<br>

