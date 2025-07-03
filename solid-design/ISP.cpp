/* 
nterface Segregation Principle (ISP)


*/


#include<iostream>
#include<string>
using namespace std;

/*
====================================================
🟦 Interface Segregation Principle (ISP)
====================================================

Definition:
➡️ A class should never be forced to implement an interface it doesn't use.

🧠 Real life:
You don’t expect a “Guest” in a library to pay fines or reserve rooms.

✅ Break big interfaces into small role-based ones.
*/

// --------------------------------------------------
// 🚫 Step 1: VIOLATE the ISP
// --------------------------------------------------

class IUser_Violation {
public:
    virtual void borrowBook() = 0;
    virtual void returnBook() = 0;
    virtual void payFine() = 0;
    virtual void reserveRoom() = 0;
};

// ❌ Guest forced to implement all, even if unused
class Guest_V : public IUser_Violation {
public:
    void borrowBook() override {
        // Guests can't borrow!
        cout << "Guests can't borrow books!\n";
    }

    void returnBook() override {
        // Guests never borrow
    }

    void payFine() override {
        // Guests don't pay fines
    }

    void reserveRoom() override {
        // Guests can't reserve rooms
    }
};

void testViolation() {
    cout << "🚫 ISP Violation:\n";
    Guest_V guest;
    guest.borrowBook(); // Meaningless call
    cout << "Guest was forced to implement irrelevant features.\n\n";
}

/*
====================================================
✅ Step 2: Respect ISP with small interfaces
====================================================

✅ Break large interface into role-specific small interfaces
*/

class IBorrowable {
public:
    virtual void borrowBook() = 0;
    virtual void returnBook() = 0;
};

class IPayable {
public:
    virtual void payFine() = 0;
};

class IReservable {
public:
    virtual void reserveRoom() = 0;
};

class IUser {
public:
    virtual string getType() = 0;
};

// ✅ Guest only implements IUser
class Guest : public IUser {
public:
    string getType() override { return "Guest"; }
};

// ✅ Student can borrow and pay fines
class Student : public IUser, public IBorrowable, public IPayable {
public:
    string getType() override { return "Student"; }

    void borrowBook() override {
        cout << getType() << " borrowed a book.\n";
    }

    void returnBook() override {
        cout << getType() << " returned a book.\n";
    }

    void payFine() override {
        cout << getType() << " paid fine.\n";
    }
};

// ✅ Librarian only reserves rooms
class Librarian : public IUser, public IReservable {
public:
    string getType() override { return "Librarian"; }

    void reserveRoom() override {
        cout << getType() << " reserved a room.\n";
    }
};

void testISP() {
    cout << "✅ ISP Compliant:\n";

    Student student;
    student.borrowBook();
    student.returnBook();
    student.payFine();

    Librarian lib;
    lib.reserveRoom();

    Guest guest;
    cout << guest.getType() << " has no borrowing functions — and that’s OK.\n";

    cout << "\n✅ All classes implement only what they need.\n";
}

int main() {
    testViolation();
    testISP();
    return 0;
}
