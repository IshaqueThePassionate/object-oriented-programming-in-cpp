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


//----------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------