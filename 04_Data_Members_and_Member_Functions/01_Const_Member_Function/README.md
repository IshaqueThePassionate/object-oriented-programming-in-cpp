# Constant Member Functions & The Mutable Keyword

#### **1. Constant Member Functions (Standard Behavior)**

A constant member function is a function inside a class declared with the `const` keyword. It guarantees that the function will **not modify** any data members of the object. It effectively makes the function "read-only."

**Key Properties:**

* **Syntax:** The keyword `const` is placed after the function parentheses.
* **Restriction:** If you try to change a variable inside this function, the compiler will throw an error.
* **Usage:** It is used for "getter" functions (functions that just return values) to ensure data safety.

**Standard Example (Strict Rule):**
In this example, the function strictly follows the `const` rule. It can read data, but it cannot change it.

```cpp
class Rectangle {
    int width;
public:
    // Constructor
    Rectangle(int w) {
        width = w;
    }

    // CONST MEMBER FUNCTION
    // This function is strictly read-only.
    int getWidth() const {
        // width = 20; // ERROR: If we uncomment this, code will fail.
        return width;  // Allowed: We are only reading the value.
    }
};

```
```cpp
#include <iostream>
using namespace std;

class Student {
private:
    char* name;

public:
    char* getName();

    void setName(char* aName);

    int ConstFunc() const {
        // name = getName();        // ❌ ERROR: const function cannot modify data members
        // setName("Ahmad");        // ❌ ERROR: cannot call non-const function inside const function
        return 0;
    }
};

// ----------------------------
// Function Definitions
// ----------------------------
char* Student::getName() {
    return name;
}

void Student::setName(char* aName) {
    name = aName;
}

// ----------------------------
// MAIN FUNCTION
// ----------------------------
int main() {

    Student s;

    s.setName((char*)"Ali");
    cout << s.getName() << endl;

    s.ConstFunc();   // allowed to call, but inside it cannot modify state

    return 0;
}
```


<br>

# 2. The `mutable` Keyword (The Exception)

**Explanation:**
Sometimes, we need to modify a specific variable even inside a `const` function (e.g., for counting how many times a function was called, or for debugging). To do this, we use the `mutable` keyword.

* **Definition:** `mutable` is a storage class specifier that allows a data member to be modified even by a `const` member function.
* **Logic:** It overrides the `const` restriction for that specific variable only.

**Example with `mutable` (Bypassing the Rule):**
Below is the `WifiConnection` example. It shows how we can read a normal variable while modifying a `mutable` variable inside a `const` function.

```cpp
#include <iostream>
#include <string>
using namespace std;

class WifiConnection {
private:
    string ssid;            // Normal variable (Cannot change in const function)
    mutable int accessCount; // Mutable variable (CAN change in const function)

public:
    // 1. CONSTRUCTOR
    // Initializes the object when it is created
    WifiConnection(string name) {
        ssid = name;
        accessCount = 0;
    }

    // 2. CONST MEMBER FUNCTION
    // This function promises not to change the object's state (ssid),
    // but because 'accessCount' is mutable, we are allowed to change it.
    void showConnectionInfo() const {
        
        // Reading normal variable (Allowed)
        cout << "Connected to: " << ssid << endl; 

        // Modifying mutable variable (Allowed because of 'mutable' keyword)
        // Even though this function is const, this line works!
        accessCount++; 
        
        // ssid = "NewNetwork"; // ERROR: This would fail because 'ssid' is not mutable
        
        cout << "This connection has been accessed " << accessCount << " times." << endl;
    }
};

int main() {
    // Creating a Constant Object
    const WifiConnection myWifi("Home_Network_5G");

    cout << "--- First Check ---" << endl;
    // Calling the const function
    myWifi.showConnectionInfo(); 

    cout << "\n--- Second Check ---" << endl;
    // Calling it again to prove the mutable variable changed
    myWifi.showConnectionInfo(); 

    return 0;
}

```

**Output:**

```text
--- First Check ---
Connected to: Home_Network_5G
This connection has been accessed 1 times.

--- Second Check ---
Connected to: Home_Network_5G
This connection has been accessed 2 times.

```


A class needs both **Data Members** (to store info) and **Member Functions** (to process info). While data is unique to every object, member functions are code shared by all objects. As a programmer, you choose to define them **Inside** for speed or **Outside** for organization.