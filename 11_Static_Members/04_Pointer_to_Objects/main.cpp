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

//-----------------------------------------------------------------------------------------------

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
