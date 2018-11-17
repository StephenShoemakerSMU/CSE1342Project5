#ifndef LIBRARY
#define LIBRARY

#include "Book.h"
#include "Shelf.h"
#include "Loan.h"

class Library{
  private:
    Shelf shelf;
    Loan loan;
  public:
    Library();
    void displayLibrary();
    void addBook(Book);
                  //bookName Fname LName Month Day Year
    void checkOutBook(string, string, string, int, int, int);
    void returnBook(string);

};

#endif
