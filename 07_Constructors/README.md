# What is a Constructor?

**Definition:**
A Constructor is a special type of member function in a class that is strictly used to initialize objects or the data members of that class. It is "special" because it is called **automatically** when an object is created.

**Properties:**

* **Same Name:** The constructor has the exact same name as the class.
* **No Return Type:** It has no return type, you do not even write `void`.
* **Automatic Call:** When you create an object, the constructor is called automatically.
* **Initialization:** Its main purpose is to provide initial values to the object's variables (data members).
* **Public:** Generally, it is defined inside the `public` section of the class.

**Basic Syntax:**

```cpp
class ClassName {
public:
    // Constructor Name is same as Class Name
    ClassName() {
        // Body of the constructor
    }
};
```

**Code Example (Default Constructor Concept):**
Here is a basic example of a constructor that runs automatically.

```cpp
class MyClass {
public:
    // This is the Constructor
    MyClass() {
        cout << "Object Created! Constructor Called." << endl;
    }
};

int main() {
    MyClass obj; // Constructor runs immediately here
    return 0;
}
```
## Why do we need Constructors?

We need constructors for three main reasons:

1.  **To Remove Garbage Values:**
    If you create a variable in C++ but do not give it a value, it holds a random "garbage" value from the computer's memory. Constructors ensure that every object starts with correct, clean values (like 0 or null) instead of random junk.

2.  **To Automate Initialization:**
    Without a constructor, you would have to manually call a setup function (like `init()`) every time you create an object. If you forget to call it, your program might crash. Constructors run automatically, so you never forget to set up your object.

3.  **To Ensure Valid Objects:**
    Constructors guarantee that an object is fully ready to be used the moment it is created.
---

### **Definition & Initialization**

**Definition:**
A constructor is a member function of a class that has the exact same name as the class itself. It is executed automatically whenever a new instance (object) of the class is created to set initial values for the object's data members.

**Code Example (Initializing Data Members):**
Here is how you use a constructor to assign initial values (initialize) to variables like `rollNumber` or `grade` inside the class.

```cpp
class Student {
public:
    int rollNumber;
    char grade;

    // Constructor initializing values
    Student() {
        rollNumber = 101;  // Setting initial value
        grade = 'A';       // Setting initial value
    }
};
```

---

### **How are they called?**

Unlike normal functions (e.g., `myFunction()`), you do not call a constructor explicitly using the dot operator.

**1. Implicit Call:**
It happens the moment you write `ClassName obj;`. This is the most common way.

**2. Explicit Call:**
You can call it explicitly when passing parameters, e.g., `ClassName obj = ClassName(10);`.

**Code Example (Implicit vs Explicit Calls):**

```cpp
class Demo {
public:
    int x;
    
    // Parameterized Constructor
    Demo(int val) {
        x = val;
    }
};

int main() {
    // Implicit Call (Common method)
    // The compiler understands you want to pass 10 to the constructor
    Demo obj1(10);

    // Explicit Call (Less common, but valid)
    // You explicitly write the constructor name to create a temporary object
    Demo obj2 = Demo(20);
    
    return 0;
}
```

---

### **Types of Constructors**

There are primarily three types of constructors in C++.

#### **1. Default Constructor**

A constructor that takes **no parameters** (arguments).

* If you do not define *any* constructor in your class, the C++ compiler automatically inserts a generic Default Constructor for you (which does nothing visible but allocates memory).
* If you define *any* constructor, the compiler stops providing the automatic one.

**Code Example (Default Constructor):**

```cpp
class Box {
public:
    int length;

    // User-defined Default Constructor
    // Takes NO arguments
    Box() {
        length = 0; // Initialize length to 0
        cout << "Default Constructor Called" << endl;
    }
};

int main() {
    Box b1; // Calls Box() automatically
    return 0;
}
```

#### **2. Parameterized Constructor**

A constructor that takes **parameters** (arguments). This allows you to initialize different objects with different values at the time of creation.

**Code Example (Parameterized Constructor):**

```cpp
class Box {
public:
    int length;

    // Parameterized Constructor
    // Takes an integer argument 'l'
    Box(int l) {
        length = l; // Assigns the passed value to the variable
        cout << "Parameterized Constructor Called. Length is: " << length << endl;
    }
};

int main() {
    Box b1(50); // Calls Box(int l) and sets length to 50
    return 0;
}
```

#### **3. Copy Constructor**

A constructor that creates a new object as an exact **copy** of an existing object. It takes a reference to an object of the same class as a parameter.

**Code Example (Copy Constructor):**

```cpp
class Box {
public:
    int length;

    // 1. Parameterized Constructor (needed to create the first object)
    Box(int l) {
        length = l;
    }

    // 2. Copy Constructor
    // Takes a reference (const Box &obj)
    Box(const Box &oldObj) {
        length = oldObj.length; // Copies length from the old object to the new one
        cout << "Copy Constructor Called" << endl;
    }
};

int main() {
    Box b1(100);      // Calls Parameterized Constructor
    
    // Calls Copy Constructor
    // Creates 'b2' as a copy of 'b1'
    Box b2 = b1;      
    
    return 0;
}
```
<br>

# Constructor Overloading

**Definition:**
Constructor overloading is a feature in C++ where a class can have multiple constructors, as long as they have unique parameter lists. This allows you to initialize objects in different ways depending on the data available at the time of creation.

use constructor overloading so that we can initialize an object in different ways. In other words, by having multiple constructors in a class, we can create objects with different sets of parameters or different types of initial values. This gives us flexibility to handle various situations and initialize our objects exactly the way we need to.

**Properties:**

* **Same Name:** All constructors must have the exact same name as the class.
* **Different Signatures:** Each constructor must differ in the **number** of parameters, the **type** of parameters, or the **sequence** of parameters.
* **No Return Type:** Constructors do not have a return type (not even `void`).
* **Automatic Call:** The specific constructor is triggered automatically when an instance (object) of the class is created.

---

### **How the Compiler Decides**

You asked how the compiler knows which constructor to call when there are multiple options. This process is known as **Overload Resolution**.

The compiler looks at the **Function Signature**. It compares the arguments you passed during object creation against the definitions in your class. It checks:

1. **Count:** How many arguments did you pass?
2. **Type:** What are the data types (e.g., `int`, `string`, `double`)?
3. **Order:** In what sequence did you pass them?

It will pick the constructor that matches the arguments exactly. If no match is found, it will look for implicit conversions (like `char` to `int`). If ambiguity remains, it throws a compile-time error.

#### **Example**

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    // Constructor 1: No parameters
    Student() {
        cout << "Object created with Default Constructor (No data)" << endl;
    }

    // Constructor 2: One parameter (ID)
    Student(int id) {
        cout << "Object created with ID: " << id << endl;
    }

    // Constructor 3: Two parameters (ID and Name)
    Student(int id, string name) {
        cout << "Object created with ID: " << id << " and Name: " << name << endl;
    }
};

int main() {
    // COMPILER DECISION LOGIC:

    // 1. Matches Constructor 1 (0 arguments)
    Student s1; 

    // 2. Matches Constructor 2 (1 int argument)
    Student s2(101); 

    // 3. Matches Constructor 3 (1 int, 1 string)
    Student s3(102, "Ali"); 

    return 0;
}
```


```cpp
#include <iostream>
#include <cstring> // Required for string manipulation functions
using namespace std;

class Student {
private:
    // --- DATA MEMBERS (Using Pointers) ---
    char* name;  // Storing the address of the string
    int rollNo;
    float gpa;

public:
    // --- CONSTRUCTOR 1: Default Constructor ---
    Student() {
        cout << "Constructor 1 Called (Default)" << endl;
        name = "Unknown"; // Pointing to a default string literal
        rollNo = 0;
        gpa = 0.0;
    }

    // --- CONSTRUCTOR 2: Name Only ---
    // Takes a pointer to a character array (char*)
    Student(char* aName) {
        cout << "Constructor 2 Called (Name Only)" << endl;
        name = aName; // Copying the ADDRESS of the name
        rollNo = 0;
        gpa = 0.0;
    }

    // --- CONSTRUCTOR 3: Name + Roll No ---
    // Matches the slide: Student(char * aName, int aRollNo)
    Student(char* aName, int aRollNo) {
        cout << "Constructor 3 Called (Name + Roll)" << endl;
        name = aName;
        
        // Validation Logic (from your slide)
        if (aRollNo < 0) {
            rollNo = 0;
            cout << "  -> Error: Negative Roll No fixed to 0." << endl;
        } else {
            rollNo = aRollNo;
        }
        gpa = 0.0;
    }

    // --- CONSTRUCTOR 4: All Details ---
    Student(char* aName, int aRollNo, float aGPA) {
        cout << "Constructor 4 Called (Full Record)" << endl;
        name = aName;
        
        if (aRollNo < 0) {
            rollNo = 0;
        } else {
            rollNo = aRollNo;
        }
        gpa = aGPA;
    }

    void display() {
        // When we print a char*, C++ prints the whole string starting from that address
        cout << "  Details -> Name: " << name 
             << " | Roll No: " << rollNo 
             << " | GPA: " << gpa << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    // Note: In C++, text in double quotes like "Ali" is a string literal.
    // It is passed as an address (pointer) to the function.

    // 1. Default
    Student student1;
    student1.display();

    // 2. Name Only (Passing char pointer)
    Student student2((char*)"Ali"); 
    student2.display();

    // 3. Name + Roll No
    Student student3((char*)"Saad", 101);
    student3.display();

    // 4. Full Details
    Student student4((char*)"Bilal", 102, 3.8);
    student4.display();
    
    return 0;
}

```

<br>

# Member Initializer List in C++

**Definition:** A Member Initializer List is a mechanism in C++ constructors that allows you to initialize class data members **before** the constructor body executes. It is placed after the constructor's parameter list, separated by a colon (`:`).

**Properties (Roman Urdu):**

* **Executes Before Body:** Ye list hamesha constructor ki main body `{ }` start honay se pehle run hoti hai.
* **True Initialization:** Iske zariye variables ko directly create kartay waqt value milti hai (Initialization), jabke body ke andar value dena "Assignment" kehlata hai.
* **Mandatory for Const:** Agar class mein koi `const` variable ho, to usay sirf initializer list ke zariye hi value di ja sakti hai; body mein usay change karna mana hai.
* **Syntax:** Isay constructor ke parameters ke baad colon (`:`) laga kar likha jata hai.

---

###  Conceptual Explanation (Descriptive Way)

To understand this, you must understand the difference between **Initialization** and **Assignment**.

Imagine you are building a house.

1. **Initialization (The Initializer List):** You pour the concrete into a mold to form a wall. The wall is created *with* its shape immediately.
2. **Assignment (The Constructor Body):** You build a plain wall first, and *then* you paint it or break parts of it to reshape it.

In C++, when you enter the `{ constructor body }`, the computer has *already* created memory for all your variables. If you write `rollNo = 10` inside the body, you are technically doing extra work: the variable was created with garbage values first, and now you are wiping it to write `10`.

The **Member Initializer List** intercepts this process. It tells the compiler: *"When you create this variable in memory, put this value in it immediately."* This is not only faster but sometimes the *only* way to set values (like for constants).

---

### Why is it Unavoidable? (Crucial Scenarios)

While you can often use the constructor body for normal variables, you are **forced** to use the Initializer List in these two main cases:

**A. For `const` Data Members**
A constant variable must be initialized the moment it is born. You cannot create a constant empty variable and fill it later.

* *Incorrect:* Creating `const int id;` inside the body and then trying `id = 5;` causes an error.
* *Correct:* Using the list `: id(5)` sets the value at the moment of creation.

**B. For Reference Members (`&`)**
Just like constants, references (aliases) must refer to something immediately upon creation. They cannot be left empty and assigned later.

---

###  Practical Code Example

Below is the exact code you provided, which perfectly demonstrates how to handle a `const` member (`rollNo`) using the initializer list.

```cpp
#include <iostream>
using namespace std;

class Student {
private:
    // const data member
    // it MUST be initialized using a member initializer list
    const int rollNo;

    // normal data members
    float GPA;
    char grade;

public:
    // -----------------------------------------
    // CONSTRUCTOR WITH MEMBER INITIALIZER LIST
    // -----------------------------------------
    // Syntax:
    // ClassName(parameters) : member1(value), member2(value) { }
    //
    // The part after ':' is called the Member Initializer List
    // It initializes data members BEFORE the constructor body executes
    Student(int r)
        : rollNo(r),    // const member initialized here (cannot be assigned later)
          GPA(0.0f),    // direct initialization (more efficient)
          grade('N')    // multiple members are separated by commas
    {
        // constructor body
        // rollNo = r;   // ❌ ERROR: const members cannot be assigned here
    }

    void setGPA(float g) {
        GPA = g;
    }

    void setGrade(char g) {
        grade = g;
    }

    // const member function
    // does not modify the object's state
    void show() const {
        cout << "Roll No: " << rollNo << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {

    // object creation
    // member initializer list runs at this point
    Student s1(101);

    s1.setGPA(3.6f);
    s1.setGrade('A');

    s1.show();

    return 0;
}

```

### Output of the Code

```plaintext
Roll No: 101
GPA: 3.6
Grade: A

```


