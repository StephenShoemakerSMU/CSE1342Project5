//Stephen Shoemaker
//Loan.h
//CSE 1342 Program 5
//11/16/18
//BookLinkedList subclass to resemble a linked list of loaned books
//Is sorted by return date
//Displayed by return date

#ifndef LOANLIST
#define LOANLIST

#include "BookLinkedList.h"
#include <string>
class Loan : public BookLinkedList{
  public:
    bool compareBooks(Book, Book);
    Book returnBook(string);
    string toString();
};

#endif
