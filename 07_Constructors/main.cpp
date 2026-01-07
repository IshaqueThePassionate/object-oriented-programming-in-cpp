#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;

public:
    
    // 1. DEFAULT CONSTRUCTOR
    
    // Definition: No arguments. Initializes with default values.
    Student() {
        id = 0;
        name = "Unknown";
        cout << "-> Default Constructor called: Object created with default values." << endl;
    }

    
    // 2. PARAMETERIZED CONSTRUCTOR
    
    // Definition: Takes arguments to set specific values.
    Student(int x_id, string x_name) {
        id = x_id;
        name = x_name;
        cout << "-> Parameterized Constructor called: Object created with ID: " << id << endl;
    }

    
    // 3. COPY CONSTRUCTOR
    
    // Definition: Creates a new object by copying data from an existing object.

    Student(const Student &obj) {
        id = obj.id;     
        name = obj.name;
        cout << "-> Copy Constructor called: Copied data from another student." << endl;
    }

    void display() {
        cout << "   [Details] ID: " << id << ", Name: " << name << endl;
    }
};

int main() {

    // 1. Calling Default Constructor
    // Implicit Call example
    
    cout << "\n1. Creating s1..." << endl;
    Student s1;
    s1.display();


    // 2. Calling Parameterized Constructor
    // Explicit Call example (Student s2 = Student(...)) works too, but this is Implicit shorthand

    cout << "\n2. Creating s2..." << endl;
    Student s2(101, "Ali");
    s2.display();


    // 3. Calling Copy Constructor
    // We initialize s3 using s2

    cout << "\n3. Creating s3 as a copy of s2..." << endl;
    Student s3 = s2;
    s3.display();

    return 0;
}