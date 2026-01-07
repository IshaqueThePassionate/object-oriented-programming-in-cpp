
class Student {
public:
    // Constructor
    Student() {
        // Code to set up things
    }

    // Destructor (Notice the ~ symbol)
    ~Student() {
        // Code to clean up things
    }
};

//-------------------------------------------------------------------------------

#include <iostream>
using namespace std;

class MyClass {
public:
    int id;

   
    // CONSTRUCTOR

    // Runs when we CREATE the object (Allocating resources)
    MyClass(int x) {
        id = x;
        cout << "-> Constructor Called for ID: " << id << " (Object Created)" << endl;
    }


    // DESTRUCTOR
  
    // Runs when the object is DESTROYED (Freeing resources)
    // Syntax: ~ClassName()
    ~MyClass() {
        cout << "-> Destructor Called for ID: " << id << " (Cleaning up & Freeing Memory)" << endl;
    }
};

int main() {
    cout << "--- Main Function Started ---" << endl;

    // 1. Creating 'obj1' in the main scope
    // This stays alive until the program ends
    MyClass obj1(1);

    // 2. Creating a specific block (scope)
    cout << "\n--- Entering specific block ---" << endl;
    {
        // 'obj2' is created inside this block
        MyClass obj2(2);
        
        cout << "   (Inside block: obj2 is working...)" << endl;
        
    } // <--- BLOCK ENDS HERE.
      // 'obj2' goes out of scope. The Destructor for obj2 runs NOW.

    cout << "--- Exited specific block ---" << endl;

    cout << "\n--- Main Function Ending ---" << endl;
    // The program ends here.
    // 'obj1' goes out of scope. The Destructor for obj1 runs NOW.
    
    return 0;
}

//-------------------------------------------------------------------------------

#include <iostream>
using namespace std;

/*
    REAL-WORLD PROBLEM:
    A Bank Account system where:
    - Data must be protected (Encapsulation)
    - Access is controlled (Access Specifiers)
    - Object starts in a valid state (Constructor)
    - Cleanup happens automatically (Destructor)
*/

class BankAccount {

private:
    // PRIVATE DATA MEMBER
    // This represents sensitive information
    // It cannot be accessed directly from outside the class
    int balance;

public:
    // CONSTRUCTOR
    // Automatically called when an object is created
    // Purpose: initialize the object into a valid state
    BankAccount(int initialBalance) {
        balance = initialBalance;
        cout << "Account created with balance: " << balance << endl;
    }

    // PUBLIC MEMBER FUNCTION
    // Provides controlled access to private data
    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        }
    }

    // PUBLIC MEMBER FUNCTION
    // Another controlled operation
    void withdraw(int amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    // PUBLIC MEMBER FUNCTION
    // Allows reading data without exposing it directly
    void showBalance() {
        cout << "Current balance: " << balance << endl;
    }

    // DESTRUCTOR
    // Automatically called when object goes out of scope
    // Used for cleanup or final actions
    ~BankAccount() {
        cout << "Account closed. Final balance was: " << balance << endl;
    }
};

int main() {

    // OBJECT CREATION
    // Constructor is called automatically here
    BankAccount account(5000);

    // Accessing object through PUBLIC interface only
    account.deposit(2000);
    account.withdraw(1500);
    account.showBalance();

    // When main() ends:
    // - object goes out of scope
    // - destructor is called automatically

    return 0;
}

