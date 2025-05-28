# 🧬 Inheritance in Object-Oriented Programming (OOP)

Inheritance is a core principle of OOP that lets one class **inherit** the properties and behavior (methods) of another class.  
It helps with **code reuse, organization, and extension**.

## 🔑 Key Concepts

| Term             | Meaning                                                                  |
| ---------------- | ------------------------------------------------------------------------ |
| `Base Class`     | The general class whose features are inherited (also called **Parent**)  |
| `Derived Class`  | The class that inherits from the base (also called **Child** or **Sub**) |
| `public` keyword | Allows derived class to access public members of base class              |

---

## 📘 Example: Simple Inheritance in C++

```cpp
#include <iostream>
using namespace std;

// Base class
class Vehicle {
public:
    void start() {
        cout << "Vehicle started" << endl;
    }
};

// Derived class
class Car : public Vehicle {
public:
    void drive() {
        cout << "Car is driving" << endl;
    }
};

int main() {
    Car myCar;
    myCar.start();
    myCar.drive();
    return 0;
}
```
