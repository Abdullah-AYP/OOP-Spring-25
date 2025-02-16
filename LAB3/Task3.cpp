#include <iostream>
#include <string>
using namespace std;

class Library {
private:
    string bookList[69]; 
    bool availableBooks[69]; 
    int totalBooks;
public:
    Library() {
        totalBooks = 0;
    }
    void addBook(const string &book) {
        if (totalBooks < 100) {
            bookList[totalBooks] = book;
            availableBooks[totalBooks] = true; 
            totalBooks++;
            cout << "Book added successfully: " << book << endl;
        } else {
            cout << "Library is full! Cannot add more books." << endl;
        }
    }
    void borrowBook(const string &book) {
        for (int i = 0; i < totalBooks; i++) {
            if (bookList[i] == book && availableBooks[i]) {
                availableBooks[i] = false;
                cout << "Book borrowed successfully: " << book << endl;
                return;
            }
        }
        cout << "Book not available for borrowing: " << book << endl;
    }
    void returnBook(const string &book) {
        for (int i = 0; i < totalBooks; i++) {
            if (bookList[i] == book && !availableBooks[i]) {
                availableBooks[i] = true;
                cout << "Book returned successfully: " << book << endl;
                return;
            }
        }
        cout << "Book not found or already available: " << book << endl;
    }
    void displayBooks() {
        cout << "\nLibrary Books:\n";
        for (int i = 0; i < totalBooks; i++) {
            cout << "- " << bookList[i] << " (" << (availableBooks[i] ? "Available" : "Borrowed") << ")" << endl;
        }
    }
};
int main() {
    Library lib;
    lib.addBook("Object Oriented Programming");
    lib.addBook("Operating Systems");
    lib.addBook("Artificial Intelligence");
    lib.displayBooks();
    lib.borrowBook("Object Oriented Programming");
    lib.displayBooks();
    lib.returnBook("Object Oriented Programming");
    lib.displayBooks();
    
    return 0;
}
