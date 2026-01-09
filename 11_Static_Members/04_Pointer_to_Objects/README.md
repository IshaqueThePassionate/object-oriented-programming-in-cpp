
---

# Pointers to Objects in C++

**Definition:** A pointer to an object is a variable that stores the memory address of an instance (object) of a class. Just as an integer pointer (`int*`) stores the address of an integer variable, a class pointer (`Student*`) stores the address of a `Student` object.

**Key Concepts:**

* **Arrow Operator (`->`):** When using a pointer to an object, you cannot use the dot (`.`) operator to access members. You must use the arrow operator (e.g., `ptr->display()`).
* **Efficiency:** Pointers are often used to pass objects to functions efficiently (by reference) to avoid creating unnecessary copies of large objects.
* **Dynamic Allocation:** Pointers are strictly required when you want to create objects in the **Heap** memory using the `new` keyword.

---

### 2. Syntax and Access

There are two ways to access members using a pointer.

**A. The Arrow Operator (Standard Way)**
This is the cleanest and most common method.

```cpp
ptr->functionName();
ptr->variableName;

```

**B. Dereferencing + Dot Operator (The "Hard" Way)**
This does the same thing but is harder to read. You first "dereference" the pointer to get the object, then use the dot.

```cpp
(*ptr).functionName(); // Parentheses are mandatory here!

```

---

### 3. Practical Code Examples

#### Example A: Dynamic Allocation (Stack vs Heap)

**Scenario:** We will demonstrate two ways to use pointers:

1. Pointing to an existing object (Stack Memory).
2. Creating a new object dynamically (Heap Memory).

```cpp
#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    int speed;

public:
    Car(string m, int s) : model(m), speed(s) {}

    void display() {
        cout << "Model: " << model << " | Speed: " << speed << " km/h" << endl;
    }
};

int main() {
    // ---------------------------------------------------------
    // CASE 1: Pointer to a Normal Object (Stack)
    // ---------------------------------------------------------
    Car myCar("Toyota Corolla", 120); // Normal object
    
    Car* ptr;      // 1. Declare pointer
    ptr = &myCar;  // 2. Store address of myCar in ptr

    cout << "--- Accessing via Stack Pointer ---" << endl;
    ptr->display(); // Accessing function using arrow operator

    // ---------------------------------------------------------
    // CASE 2: Pointer to a Dynamic Object (Heap)
    // ---------------------------------------------------------
    // We use 'new' to create an object manually in Heap memory.
    // 'new' returns the address, which we store in 'heapPtr'.
    Car* heapPtr = new Car("Honda Civic", 180);

    cout << "\n--- Accessing via Heap Pointer ---" << endl;
    heapPtr->display();

    // IMPORTANT: Objects created with 'new' must be deleted manually!
    delete heapPtr; 
    
    return 0;
}

```

#### Example B: Pointer Syntax (Your Student Example)

**Scenario:** This example demonstrates creating a pointer `ptr` that points to an existing object `obj`. We then use the arrow operator `->` through the pointer to modify the object's data.

```cpp
#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    char* name;

public:
    // Default constructor
    Student() {
        rollNo = 0;
        name = NULL;
    }

    // Parameterized constructor
    Student(char* aName) {
        name = aName;
        rollNo = 0;
    }

    // Member function
    void setRollNo(int aNo) {
        rollNo = aNo;
    }

    void show() {
        cout << "Roll No: " << rollNo << endl;
        if (name != NULL)
            cout << "Name: " << name << endl;
        else
            cout << "Name: Not Set" << endl;
    }
};

int main() {

    Student obj;        // object creation
    Student* ptr;       // pointer to Student

    ptr = &obj;         // pointer pointing to object
    ptr->setRollNo(10); // accessing member function using pointer

    obj.show();

    return 0;
}

```

### Output of the Code (Example B)

```plaintext
Roll No: 10
Name: Not Set

```

---

### 4. Why Do We Need This? (Exam Logic)

You might ask: *"Why not just use `obj.display()`? Why complicate things with `ptr->display()`?"*

1. **Polymorphism (OOP Core):** You cannot achieve Polymorphism (a major OOP concept) without pointers. A pointer of a **Parent Class** can point to a **Child Class** object. This is the foundation of virtual functions.
* *Example:* `Animal* ptr = new Dog();`


2. **Dynamic Memory Management:** If you don't know how many objects you need until the program runs (e.g., a game spawning enemies), you must use pointers and `new` to create them on the fly.
3. **Efficiency:** Passing a pointer to a function (`func(Student* s)`) is much faster than passing the whole object by value, as it only copies the memory address (usually 4 or 8 bytes) rather than the entire object data.

### Summary 

* **Declaration:** `ClassName* ptrName;`
* **Assignment:** `ptrName = &object;`
* **Access:** Use the arrow operator `->`.
* **Memory:** Pointers are the bridge to managing **Heap** memory.