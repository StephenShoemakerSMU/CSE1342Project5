#ifndef LOANLIST
#define LOANLIST

#include "BookLinkedList.h"
#include <string>
class Loan : public BookLinkedList{
  public:
    bool compareBooks(Book, Book);
    Book returnBook(string);

};

#endif
