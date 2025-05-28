# Day 1

## Recap: OOP Concepts – Encapsulation & Abstraction

This section provides a recap of Object-Oriented Programming (OOP) concepts, specifically focusing on **Encapsulation** and **Abstraction**. These are foundational ideas you should understand before starting System Design.

---

### 🔒 Encapsulation

Encapsulation is the process of **hiding an object's internal state** and requiring all interaction to be performed through an object's methods.

#### ✅ Key Points:

- Wraps **data (variables)** and **methods (functions)** inside a class.
- Makes fields `private` and provides `public` methods (getters/setters) to access or update them.
- Helps in protecting data and maintaining object integrity.

Encapsulation is a core principle of OOP that restricts direct access to an object's data and only exposes what’s necessary through a controlled interface (like getters and setters).

Here’s a quick summary of what proper encapsulation looks like:

| Concept          | What to Ensure                                               |
| ---------------- | ------------------------------------------------------------ |
| `private` data   | ✅ Prevents external modification                            |
| Getters/Setters  | ✅ Use them instead of direct access                         |
| Logic in setters | ✅ Add checks before modifying values                        |
| Clean interface  | ✅ Users of the class don’t need to know how it works inside |

### ✅ Why Encapsulation Matters

- Keeps data safe and consistent.
- Makes code easier to maintain and debug.
- Allows internal changes without affecting other parts of the code.

> Example: `car.setSpeed(-100)` can be safely blocked inside the setter method instead of letting `speed = -100` directly.

### 🛡️ Abstraction

Abstraction is the concept of **simplifying complex systems** by modeling classes based on the essential properties and behaviors an object should have, while hiding unnecessary details.

#### ✅ Key Points:

- Focuses on **what an object does** rather than how it does it.
- Allows you to define a class with abstract methods that must be implemented by derived classes.
- Helps in reducing complexity by hiding implementation details.

#### 🔍 Example (c++):
