# Array of Objects in C++

**Definition:** An array of objects is simply an array where each element is an instance (object) of a specific class, rather than a standard data type like `int` or `float`. It allows you to store and manage multiple objects of the same class under a single name.

**Concept:**
Just as `int arr[10]` stores 10 integers, `Student arr[10]` stores 10 Student objects continuously in memory.

---

### 2. Strict Condition (Crucial Rule)

we can create an array of objects, but there is one **strict condition** you must be aware of regarding Constructors.

**The Default Constructor Rule:**
If you declare an array like `Student list[5];`, the compiler immediately creates 5 objects. To do this, it calls the **Default Constructor** (the constructor with no arguments) for every single object.

* **Condition 1:** If your class has **NO** constructors defined, it works automatically (compiler generates a default one).
* **Condition 2:** If you have defined a **Parameterized Constructor**, you **MUST** also explicitly define a **Default Constructor**. If you don't, the compiler will show an error because it doesn't know how to initialize the array elements.

---

### 3. Syntax and Initialization

There are two ways to initialize arrays of objects.

**A. Using Default Constructor (Most Common)**
You declare the array first, then set values later using a loop or manual assignment.

```cpp
Student list[3]; // Calls Default Constructor 3 times

```

**B. Using Parameterized Constructor (Inline)**
You can initialize objects at the exact moment of array creation using an initializer list.

```cpp
Student list[3] = { Student("Ali"), Student("Zara"), Student("Bilal") };

```

---

### 4. Practical Code Example

**Scenario:** We want to store records for 3 Books. Since we are creating an array `library[3]`, the class must have a Default Constructor.

```cpp
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;

public:
    // 1. DEFAULT CONSTRUCTOR (Mandatory for Array declaration)
    // The compiler needs this to create 'library[3]' initially.
    Book() {
        id = 0;
        title = "Untitled";
    }

    // 2. PARAMETERIZED CONSTRUCTOR
    // Used if we want to set data manually later
    Book(int i, string t) {
        id = i;
        title = t;
    }

    // Helper function to set data
    void setData(int i, string t) {
        id = i;
        title = t;
    }

    void display() const {
        cout << "Book ID: " << id << " | Title: " << title << endl;
    }
};

int main() {
    // ---------------------------------------------------------
    // STEP 1: Creating Array of Objects
    // ---------------------------------------------------------
    // This line creates 3 objects.
    // The 'Default Constructor' is called 3 times here.
    Book library[3]; 

    // ---------------------------------------------------------
    // STEP 2: Initializing the Objects
    // ---------------------------------------------------------
    // We access them using index [0], [1], [2] just like int arrays.
    
    library[0].setData(101, "C++ Programming");
    library[1].setData(102, "Database Systems");
    library[2].setData(103, "Data Structures");

    // ---------------------------------------------------------
    // STEP 3: Displaying via Loop
    // ---------------------------------------------------------
    cout << "--- Library Collection ---" << endl;
    
    for (int i = 0; i < 3; i++) {
        // Accessing member function for each object
        library[i].display();
    }

    return 0;
}

```

### Output of the Code

```plaintext
--- Library Collection ---
Book ID: 101 | Title: C++ Programming
Book ID: 102 | Title: Database Systems
Book ID: 103 | Title: Data Structures

```

### Summary for Exam

1. **Syntax:** `ClassName arrayName[Size];`
2. **Access:** Use index `arrayName[i].function();`
3. **Memory:** Objects are stored strictly continuously in memory.
4. **Restriction:** Always ensure a **Default Constructor** exists if you are declaring a simple array of objects.