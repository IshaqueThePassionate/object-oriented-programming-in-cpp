
class Student {
    int rollNo;
    float cgpa;
};



#include <iostream>
using namespace std;

class Student {
public:
    int rollNo;
    float cgpa;
};

int main() {
    Student student1;      // object creation
    student1.rollNo = 101;
    student1.cgpa   = 3.8;

    cout << "Roll No: " << student1.rollNo << "\n";
    cout << "CGPA: " << student1.cgpa << endl;
    return 0;
}