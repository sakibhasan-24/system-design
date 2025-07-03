#include<iostream>
#include<string>
using namespace std;

/*
====================================================
🟥 Dependency Inversion Principle (DIP)
====================================================

🧠 Big idea:
➡️ High-level classes (like LibraryManager)
    should depend on interfaces, not concrete details (like MySQL).

➡️ This makes your code flexible, swappable, and testable.
*/

// --------------------------------------------------
// 🚫 Step 1: VIOLATE DIP
// --------------------------------------------------

class MySQLDatabase_V {
public:
    void saveBook(string name) {
        cout << "Saving book to MySQL: " << name << endl;
    }
};

// ❌ LibraryManager is tightly coupled with MySQL
class LibraryManager_V {
    MySQLDatabase_V db;
public:
    void addBook(string name) {
        db.saveBook(name); // Can't switch to MongoDB easily!
    }
};

void testViolation() {
    cout << "🚫 DIP Violation:\n";
    LibraryManager_V manager;
    manager.addBook("C++ for Beginners");
    cout << "❌ LibraryManager depends directly on MySQL class.\n\n";
}

/*
====================================================
✅ Step 2: Fix with DIP
====================================================
*/

class IDatabase {
public:
    virtual void saveBook(string name) = 0;
    virtual ~IDatabase() {}
};

// ✅ Now you can plug in any implementation

class MySQLDatabase : public IDatabase {
public:
    void saveBook(string name) override {
        cout << "Saving book to MySQL: " << name << endl;
    }
};

class MongoDB : public IDatabase {
public:
    void saveBook(string name) override {
        cout << "Saving book to MongoDB: " << name << endl;
    }
};

// ✅ LibraryManager depends on abstraction, not details
class LibraryManager {
    IDatabase* database;
public:
    LibraryManager(IDatabase* db) : database(db) {}

    void addBook(string name) {
        database->saveBook(name);
    }
};

void testDIP() {
    cout << "✅ DIP Compliant:\n";

    MySQLDatabase mysql;
    MongoDB mongo;

    LibraryManager manager1(&mysql);
    manager1.addBook("Design Patterns");

    LibraryManager manager2(&mongo);
    manager2.addBook("Data Structures");

    cout << "✅ Now we can switch database without touching LibraryManager!\n";
}

int main() {
    testViolation();
    testDIP();
    return 0;
}
