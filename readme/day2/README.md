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

# 🎭 Polymorphism in Object-Oriented Programming (OOP)

**Polymorphism** allows functions to behave differently based on the object calling them.  
It's a powerful OOP concept for achieving **flexibility** and **extensibility** in your code.

## 🔑 Key Concepts

| Term                   | Meaning                                                                    |
| ---------------------- | -------------------------------------------------------------------------- |
| `Virtual` function     | A function in the base class meant to be **overridden** in derived classes |
| `Override`             | Redefining a base class method in the derived class                        |
| `Base Pointer`         | A pointer to the base class can point to derived class objects             |
| `Runtime Polymorphism` | Behavior is determined at **runtime** via virtual functions                |

---

## 📘 Example: Simple Polymorphism in C++

```cpp
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    virtual void speak() {
        cout << "Animal makes a sound" << endl;
    }
};

// Derived class 1
class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog says Woof!" << endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat says Meow!" << endl;
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->speak();  // Output: Dog says Woof!
    a2->speak();  // Output: Cat says Meow!

    delete a1;
    delete a2;

    return 0;
}
```

---

## ✅ Why It Needs

- Write **generalized code** that works with many types
- Add new types without changing existing logic
- Follows the **Open-Closed Principle** (Open for extension, closed for modification)
