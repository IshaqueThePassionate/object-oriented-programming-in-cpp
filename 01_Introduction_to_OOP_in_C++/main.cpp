#include <iostream>
using namespace std;

class Student {
public:
    int rollNo;
    float cgpa;

    void display() {
        cout << "Roll No: " << rollNo << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

int main() {
    Student s1;
    s1.rollNo = 101;
    s1.cgpa = 3.7;
    s1.display();
    return 0;
}

