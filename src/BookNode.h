#ifndef BOONODE
#define BOONODE
#include "Book.h"
class BookNode{
  private:
    Book book;
    BookNode * nextNode;
  public:
    BookNode(Book);
    BookNode * getNextNode();
    void setNextNode(BookNode*);
    Book getBook();
};

#endif
