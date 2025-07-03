/* 
Don't give your child class powers it can't handle




*/


#include<iostream>
#include<string>
using namespace std;

/*
====================================================
🟩 Liskov Substitution Principle (LSP)
====================================================

Definition:
➡️ Subclasses should be replaceable with their base classes
➡️ Without breaking program behavior

🧠 Real-life analogy:
If `User` is a parent class,
Then `Student` or `Teacher` (child) should work anywhere a `User` is expected — without breaking the code.

Let’s violate this first.
*/

// --------------------------------------------------
// 🚫 Step 1: VIOLATE the LSP
// --------------------------------------------------

// Parent class: User
class User_Violation {
public:
    virtual void borrowBook() {
        cout << "User borrowed a book.\n";
    }
};

// Child class: Student – OK
class Student_V : public User_Violation {
public:
    void borrowBook() override {
        cout << "Student borrowed a book.\n";
    }
};

// ❌ Child class: Guest – but guests are not allowed to borrow
class Guest_V : public User_Violation {
public:
    void borrowBook() override {
        throw runtime_error("Guest cannot borrow books! LSP violated.");
    }
};

// A function that assumes all users can borrow books
void issueBook(User_Violation* user) {
    user->borrowBook();
}

void testViolation() {
    cout << "🚫 LSP Violation:\n";

    Student_V student;
    issueBook(&student); // ✅ OK

    Guest_V guest;
    try {
        issueBook(&guest); // ❌ Throws error – not safe
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\n❌ Guest broke the rule of being a valid 'User'\n";
}

/*
====================================================
✅ Step 2: Fix design to FOLLOW LSP
====================================================

💡 Fix: Don't assume all users can borrow books.

Instead, separate the borrowing ability into an interface.

Now only students/teachers implement "BorrowableUser"
*/

class IUser {
public:
    virtual string getType() = 0;
    virtual ~IUser() {}
};

// Interface for users who CAN borrow
class IBorrowable {
public:
    virtual void borrowBook() = 0;
};

// ✅ Student implements both IUser and IBorrowable
class Student : public IUser, public IBorrowable {
public:
    string getType() override { return "Student"; }
    void borrowBook() override {
        cout << getType() << " borrowed a book.\n";
    }
};

// ✅ Teacher can also borrow
class Teacher : public IUser, public IBorrowable {
public:
    string getType() override { return "Teacher"; }
    void borrowBook() override {
        cout << getType() << " borrowed a book.\n";
    }
};

// ✅ Guest is still a valid User, but cannot borrow
class Guest : public IUser {
public:
    string getType() override { return "Guest"; }
    // Does NOT implement borrowBook()
};

// Now this function only accepts Borrowable users
void issueBorrowableBook(IBorrowable* user) {
    user->borrowBook();
}

void testLSP() {
    cout << "\n✅ LSP Compliant:\n";

    Student s;
    Teacher t;
    Guest g;

    issueBorrowableBook(&s);
    issueBorrowableBook(&t);
    cout << g.getType() << " cannot borrow books (but still a valid user).\n";

    cout << "\n✅ All users behave properly. No violations. System is safe.\n";
}

int main() {
    testViolation();
    testLSP();
    return 0;
}
