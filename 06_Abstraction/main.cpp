
// Snippet 1 – Simple Abstraction (Printer)

class Printer {
public:
    void print() {
        // User only sees this function
        // HOW printing happens is hidden
        // This is abstraction
    }
};


//---------------------------------------------------------------------------
// Snippet 2 – Abstraction via Public Interface & Hidden Implementation (Car)

class Car {
public:
    void start() {
        // User calls start()
        // Internal engine logic is hidden
        // This method represents abstraction
        igniteEngine();
    }

private:
    void igniteEngine() {
        // Complex engine process
        // User never sees or calls this
    }
};


//---------------------------------------------------------------------------
// Snippet 3 – Pure Abstraction with an Abstract Class (Shape)

class Shape {
public:
    virtual void draw() = 0; // pure virtual function
    // Forces derived classes to provide their own implementation
    // This is pure abstraction
};

