# What is a Destructor?

A **Destructor** is a special member function of a class that is executed **automatically** when an object is destroyed or goes out of scope. Its primary purpose is to free up resources and memory that the object acquired during its life.

IT has the exact same name as the class but is preceded by a tilde symbol (`~`). It is used to deallocate memory and release resources (like closing files) when the object is no longer needed.

**Real-World Analogy:**
Think of an object like **renting a Hotel Room**.

* **Constructor (Check-in):** You arrive, sign the papers, get the keys, and put your luggage in the room. You are setting everything up.
* **Object Life (Stay):** You live in the room, use the lights, water, and TV.
* **Destructor (Check-out):** Before you leave forever, you must return the keys, pay the bill, and take your luggage out. If you leave without doing this (without a destructor), the hotel thinks the room is still occupied, and no one else can use it. This creates a mess (Memory Leak).

---

### **Properties of a Destructor**

* **Tilde Sign:** It has the same name as the class, but you must put a tilde (`~`) sign before it.
* **No Return Type:** It has no return type. You do not even write `void`.
* **No Parameters:** A destructor **cannot** take any arguments.
* **No Overloading:** Because it cannot take arguments, a class can have only **one** destructor.
* **Automatic Call:** You never call it manually; the compiler calls it automatically when the object dies.
* **Reverse Order:** Objects are destroyed in the reverse order of their creation. ( The last object created is the first one to be destroyed).

---

### **Why do we need Destructors? (Memory & Resources)**

We need destructors for "Housekeeping." This is where we address your specific point about freeing memory:

1. **Freeing Dynamic Memory (Important):**
   If your Constructor allocated memory manually using the `new` keyword (Dynamic Memory), the computer does **not** clear this automatically. The Destructor is essential here. It uses the `delete` keyword to free that specific memory. If you don't do this, that memory remains blocked forever (a Memory Leak).

* *Simple rule:* The Destructor frees up the memory and resources that were allocated to the object.

2. **Releasing External Resources:**
   If the object opened a text file, connected to a database, or established a network connection, the destructor ensures these are closed properly.

---

### **Basic Syntax**

```cpp
class Student {
public:
    // Constructor
    Student() {
        // Code to set up things
    }

    // Destructor (Notice the ~ symbol)
    ~Student() {
        // Code to clean up things
    }
};
```

---

### **When is the Destructor Called?**

The destructor triggers automatically in these situations:

1. **End of Scope:** When a local variable (object) goes out of the curly brackets `{ }` where it was created.
2. **Program Exit:** When the `main()` function ends, all remaining objects are destroyed.
3. **Explicit Deletion:** If you used a pointer to create an object, the destructor runs when you use `delete pointerName;`.

---

### **Detailed Code Example**

This code demonstrates the creation and automatic destruction of objects. Pay attention to the comments to see how the destructor cleans up "in reverse order."

```cpp
#include <iostream>
using namespace std;

class MyClass {
public:
    int id;

   
    // CONSTRUCTOR

    // Runs when we CREATE the object (Allocating resources)
    MyClass(int x) {
        id = x;
        cout << "-> Constructor Called for ID: " << id << " (Object Created)" << endl;
    }


    // DESTRUCTOR
  
    // Runs when the object is DESTROYED (Freeing resources)
    // Syntax: ~ClassName()
    ~MyClass() {
        cout << "-> Destructor Called for ID: " << id << " (Cleaning up & Freeing Memory)" << endl;
    }
};

int main() {
    cout << "--- Main Function Started ---" << endl;

    // 1. Creating 'obj1' in the main scope
    // This stays alive until the program ends
    MyClass obj1(1);

    // 2. Creating a specific block (scope)
    cout << "\n--- Entering specific block ---" << endl;
    {
        // 'obj2' is created inside this block
        MyClass obj2(2);
        
        cout << "   (Inside block: obj2 is working...)" << endl;
        
    } // <--- BLOCK ENDS HERE.
      // 'obj2' goes out of scope. The Destructor for obj2 runs NOW.

    cout << "--- Exited specific block ---" << endl;

    cout << "\n--- Main Function Ending ---" << endl;
    // The program ends here.
    // 'obj1' goes out of scope. The Destructor for obj1 runs NOW.
    
    return 0;
}
```

```cpp
#include <iostream>
using namespace std;

/*
    REAL-WORLD PROBLEM:
    A Bank Account system where:
    - Data must be protected (Encapsulation)
    - Access is controlled (Access Specifiers)
    - Object starts in a valid state (Constructor)
    - Cleanup happens automatically (Destructor)
*/

class BankAccount {

private:
    // PRIVATE DATA MEMBER
    // This represents sensitive information
    // It cannot be accessed directly from outside the class
    int balance;

public:
    // CONSTRUCTOR
    // Automatically called when an object is created
    // Purpose: initialize the object into a valid state
    BankAccount(int initialBalance) {
        balance = initialBalance;
        cout << "Account created with balance: " << balance << endl;
    }

    // PUBLIC MEMBER FUNCTION
    // Provides controlled access to private data
    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        }
    }

    // PUBLIC MEMBER FUNCTION
    // Another controlled operation
    void withdraw(int amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    // PUBLIC MEMBER FUNCTION
    // Allows reading data without exposing it directly
    void showBalance() {
        cout << "Current balance: " << balance << endl;
    }

    // DESTRUCTOR
    // Automatically called when object goes out of scope
    // Used for cleanup or final actions
    ~BankAccount() {
        cout << "Account closed. Final balance was: " << balance << endl;
    }
};

int main() {

    // OBJECT CREATION
    // Constructor is called automatically here
    BankAccount account(5000);

    // Accessing object through PUBLIC interface only
    account.deposit(2000);
    account.withdraw(1500);
    account.showBalance();

    // When main() ends:
    // - object goes out of scope
    // - destructor is called automatically

    return 0;
}
```

```cpp
#include <iostream>
#include <cstring>
using namespace std;

class Student {
    char* name;

public:
    // Constructor: heap memory allocate
    Student(const char* n) {
        int len = strlen(n);
        name = new char[len + 1];
        strcpy(name, n);

        cout << "Constructor: Memory allocated on heap" << endl;
    }

    // Destructor: heap memory free
    ~Student() {
        if (name) {
            delete [] name;
            cout << "Destructor: Heap memory released" << endl;
        }
    }

    void display() {
        cout << "Name: " << name << endl;
    }
};

int main() {
    Student s1("Ahmad");
    s1.display();

    return 0;   // yahan destructor automatically call hoga
}
```

```cpp
#include <iostream>
#include <cstring>
using namespace std;

class Student {
    char* name;

public:
    // Constructor declaration
    Student(char* aName);

    // Destructor declaration
    ~Student();
};

// -------- Constructor definition --------
Student::Student(char* aName) {
    int len = strlen(aName);
    name = new char[len + 1];
    strcpy(name, aName);

    cout << aName << " ConsIn" << endl;
}

// -------- Destructor definition --------
Student::~Student() {
    cout << name << " DestIn" << endl;
    delete [] name;
}

// -------- main --------
int main() {
    Student studentB("Ali");
    Student studentA("Ahmad");
    return 0;
}


```


