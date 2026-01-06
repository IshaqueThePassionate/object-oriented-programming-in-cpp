#include <iostream>
using namespace std;


class Student {
    // These are Data Members
    int rollNo; 
    float cgpa;
};

// -----------------------------------------------------------------------------------

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
// -----------------------------------------------------------------------------------

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

// -----------------------------------------------------------------------------------


