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
