//Stephen Shoemaker
//Library.cpp
//CSE 1342 Program 5
//11/16/18
//This is the header for the library class
//This class manages a Shelf class and a Loan class and the communication
//between them and the driver file
//It also generates the textFiles for the output

#ifndef LIBRARY
#define LIBRARY

#include "Book.h"
#include "Shelf.h"
#include "Loan.h"
#include <fstream>
#include <iostream>

class Library{
  private:
    //Shelf Linked List
    Shelf shelf;

    //Loan Linked List
    Loan loan;

    //Takes a string command and runs it
    void addRecord(string);
    void loanRecord(string);
    void returnRecord(string);
  public:
    //Displays shelf and loan
    void displayLibrary();

    //Adds a book to the library
    void addBook(Book);

    //Loans out a book from the library
                  //bookName Fname LName Month Day Year
    void checkOutBook(string, string, string, int, int, int);

    //Returns a book to the library
    void returnBook(string);

    //Processes a bookList of commands
    //uses addRecord, LoanRecord, and returnRecord as helper functions
    void processBookList(string);

    //creates textFiles to store shelf and loan records
    void produceTextFiles();

};

#endif
