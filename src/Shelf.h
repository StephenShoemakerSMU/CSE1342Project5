#ifndef SHELF
#define SHELF

#include "BookLinkedList.h"
#include <string>
class Shelf : public BookLinkedList{
  public:
    bool compareBooks(Book, Book);
    BookNode* loanOut(string);
};

#endif
