#include <iostream>
using namespace std;

class Box {
public:
    int length;

    // Normal Parameterized Constructor
    Box(int l) {
        length = l;
    }

    // Note: We did NOT write a Copy Constructor here.
    // The compiler provides a "Default" one that copies values 1-to-1.

    void display() {
        cout << "Length of Box: " << length << endl;
    }
};

int main() {
    // 1. Original Object
    Box b1(50);
    cout << "Original "; b1.display();

    // 2. The Copy
    // The compiler sees we are creating 'b2' from 'b1'.
    // It automatically copies the value 50 into b2.
    Box b2 = b1;
    cout << "Copied   "; b2.display();

    return 0;
}


//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

class Shallow {
public:
    int* data; // A POINTER member

    // Constructor: Allocates memory
    Shallow(int val) {
        data = new int(val);
    }

    // We rely on the DEFAULT Copy Constructor here.
    // It performs a SHALLOW COPY (copies the address only).

    // Destructor
    ~Shallow() {
        // In a real scenario, this would cause a crash because
        // both objects try to delete the same address.
        // delete data;
    }

    void display() {
        cout << "Value: " << *data << " | Address: " << data << endl;
    }
};

int main() {
    Shallow obj1(100);
    cout << "Obj1: "; obj1.display();

    // Shallow Copy happens here
    Shallow obj2 = obj1;
    cout << "Obj2: "; obj2.display();

    // RESULT: Both addresses are IDENTICAL. They share the memory.
    return 0;
}


//-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

class Deep {
public:
    int* data;

    // 1. Normal Constructor
    Deep(int val) {
        data = new int(val); // Allocates initial memory
    }

    // 2. CUSTOM COPY CONSTRUCTOR (The Fix)
    // Must pass by Reference (const Deep &source) to avoid recursion
    Deep(const Deep &source) {
        // Step A: Allocate NEW separate memory
        data = new int;
        
        // Step B: Copy the ACTUAL VALUE from the source into the new memory
        *data = *source.data;
        
        cout << "Copy Constructor: New memory allocated at " << data << endl;
    }

    // 3. Destructor
    ~Deep() {
        delete data; // Safe to delete because every object has its own unique memory
    }

    void display() {
        cout << "Value: " << *data << " | Address: " << data << endl;
    }
};

int main() {
    cout << "--- Creating Obj1 ---" << endl;
    Deep obj1(10);
    cout << "Obj1: "; obj1.display();

    cout << "\n--- Creating Obj2 (Deep Copy) ---" << endl;
    Deep obj2 = obj1; // Our Custom Copy Constructor runs here
    cout << "Obj2: "; obj2.display();

    // VERIFICATION:
    // 1. The Addresses are DIFFERENT.
    // 2. Changing obj1 will NOT affect obj2.
    // 3. No crash when destructors run.
    
    return 0;
}