//Stephen Shoemaker
//BookNode.h
//CSE 1342 Program 5
//11/15/18
//This class is a BookNode for a linked List
//it is essentially a book and a pointer to the next book

#ifndef BOOKNODE
#define BOOKNODE
#include "Book.h"
class BookNode{
  private:
    //Data value
    Book book;
    //Pointer to the next node
    BookNode * nextNode;
  public:
    BookNode(Book);//Single-Argument Constructor
    ~BookNode();//Destructor
    BookNode * getNextNode();//returns the next node
    void setNextNode(BookNode*);//sets the next node
    Book getBook();//returns the data
};

#endif
