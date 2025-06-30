#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*

------------------------------------------
--------- Step 1: Let's VIOLATE the SRP principle----------
------------------------------------------

One Class = One Responsibility = One Reason to Change
But here we're doing multiple things inside one class.

*/

//  A class that both defines a book AND handles logic to add/save it
class Book_Violation {
public:
    string name;
    string author;

    void addBook(string name, string author) {
        // This method sets values
        this->name = name;
        this->author = author;

        // Also saves the book — mixing logic!
        cout << "Saving book to database: " << name << " by " << author << endl;
    }
};

/*
 Why is this a violation of SRP?

1. The class is doing 2 jobs:
    - Representing a Book (data)
    - Handling logic for saving (business rule)
2. In real projects, changes in save logic (e.g. switch to file or API) will force developer to modify this class.
3. This increases coupling and reduces maintainability.

✅ SRP says:
   ➤ Class should have only one reason to change.
   ➤ So, we split responsibilities into separate classes.

------------------------------------------
✅ Step 2: Fixing the Violation using SRP
------------------------------------------
*/

// ✅ Class 1: Pure Data Class (only holds book info)
class Book {
public:
    string name;
    string author;

    Book(string name, string author) {
        this->name = name;
        this->author = author;
    }
};

// ✅ Class 2: Handles only saving/storing logic
class BookStore {
public:
    void save(const Book& book) {
        // Saving logic is now separated
        cout << "Saving book to database: " << book.name << " by " << book.author << endl;
    }
};

// ✅ Class 3: Handles adding, managing, listing books
class LibraryManager {
private:
    vector<Book> books;
    BookStore store;    

public:
    void addBook(string name, string author) {
        Book book(name, author);
        books.push_back(book);
        store.save(book); 
    }

    void showAllBooks() {
        cout << "\n--- All Books ---\n";
        for (const auto& book : books) {
            cout << "Book: " << book.name << " | Author: " << book.author << endl;
        }
    }
};

int main() {
    cout << "=== SRP Violation ===\n";
    Book_Violation b1;
    b1.addBook("1984", "George Orwell");

    /*
    Above, Book_Violation class is doing:
    1 Defining data (book)
    2 Business logic (saving)
    3 If you want to change how books are saved, you have to change this class.
    4 That’s a violation of SRP.
    */

    cout << "\n=== SRP Respected ===\n";
    LibraryManager manager;
    manager.addBook("The Alchemist", "Paulo Coelho");
    manager.addBook("Clean Code", "Robert C. Martin");
    manager.showAllBooks();

    return 0;
}

