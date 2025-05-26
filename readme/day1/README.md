# Day 1

## Recap: OOP Concepts – Encapsulation & Abstraction

This section provides a recap of Object-Oriented Programming (OOP) concepts, specifically focusing on **Encapsulation** and **Abstraction**. These are foundational ideas you should understand before starting System Design.

---

### 🛡️ Encapsulation

Encapsulation is the process of **hiding an object's internal state** and requiring all interaction to be performed through an object's methods.

#### ✅ Key Points:

- Wraps **data (variables)** and **methods (functions)** inside a class.
- Makes fields `private` and provides `public` methods (getters/setters) to access or update them.
- Helps in protecting data and maintaining object integrity.

#### 🔍 Example (C++):

```cpp
class Car {
  private:
    int speed; // Hidden from outside

  public:
    void setSpeed(int s) { speed = s; }
    int getSpeed() { return speed; }
};

```
