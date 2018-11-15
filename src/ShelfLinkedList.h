#ifndef SHELF
#define SHELF

#include "BookNode.h"
#include "Book.h"
class ShelfLinkedList{
  private:
    BookNode* headNode;
  public:
    ShelfLinkedList();
    ShelfLinkedList(Book);
    void add(Book);
    void display();

};

#endif
