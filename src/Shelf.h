//Stephen Shoemaker
//Shelf.h
//CSE 1342 Program 5
//11/15/18
//BookLinkedList subclass to resemble a linked list of books on shelf
//Is sorted by size
//Displayed by size

#ifndef SHELF
#define SHELF

#include "BookLinkedList.h"
#include <string>
class Shelf : public BookLinkedList{
  public:
    bool compareBooks(Book, Book);
    Book loanOut(string);
};

#endif
