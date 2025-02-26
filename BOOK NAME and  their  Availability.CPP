#include <iostream>
#include <string>
const int MAX_BOOKS = 5;
class Library {
private:
    std::string* books[MAX_BOOKS];
    int availableBooks; 
public:
    Library() : availableBooks(0) {}
    void addBook(const std::string& bookName) {
        if (availableBooks < MAX_BOOKS) {
            books[availableBooks] = new std::string(bookName);
            availableBooks++;
        } else {
            std::cout << "Library is full! Cannot add more books." << std::endl;
        }
    }
    void displayBooks() const {
        std::cout << "Available Books:" << std::endl;
        for (int i = 0; i < availableBooks; ++i) {
            std::cout << *(books[i]) << std::endl;
        }
    }
    void checkOutBook(const std::string& bookName) {
        for (int i = 0; i < availableBooks; ++i) {
            if (*(books[i]) == bookName) {
                std::cout << "You have checked out: " << *(books[i]) << std::endl;
                delete books[i];
                for (int j = i; j < availableBooks - 1; ++j) {
                    books[j] = books[j + 1];
                }
                books[availableBooks - 1] = nullptr;
                availableBooks--;
                return;
            }
        }
        std::cout << "Book not found!" << std::endl;
    }
    ~Library() {
        for (int i = 0; i < availableBooks; ++i) {
            delete books[i]; 
        }
    }
};
int main() {
    Library library;
    library.addBook("The Great Gatsby");
    library.addBook("1984");
    library.addBook("To Kill a Mockingbird");
    library.addBook("The Catcher in the Rye");
    library.addBook("Moby Dick");
    library.displayBooks();
    std::string bookToCheckOut;
    std::cout << "Enter the name of the book you want to check out:";
    std::getline(std::cin, bookToCheckOut);
    library.checkOutBook(bookToCheckOut);
    library.displayBooks();
    return 0;
}
