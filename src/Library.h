#ifndef LIBRARY
#define LIBRARY

#include "Book.h"
#include "Shelf.h"
#include "Loan.h"
#include <fstream>
#include <iostream>

class Library{
  private:
    Shelf shelf;
    Loan loan;
    void addRecord(string);
    void loanRecord(string);
    void returnRecord(string);
  public:
    void displayLibrary();
    void addBook(Book);
                  //bookName Fname LName Month Day Year
    void checkOutBook(string, string, string, int, int, int);
    void returnBook(string);

    void processBookList(string);
    void produceTextFiles();

};

#endif
