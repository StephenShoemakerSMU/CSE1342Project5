#ifndef LIBRARY
#define LIBRARY

#include "Book.h"
#include "Shelf.h"

class Library{
  private:
    Shelf shelf;
  public:
    Library();
    void displayLibrary();
    void addBook(Book);
                  //bookName Fname LName Month Day Year
    void checkOutBook(string, string, string, int, int, int);

};

#endif
