#ifndef BOOKLINKED
#define BOOKLINKED

#include "BookNode.h"
#include "Book.h"
class BookLinkedList{
    protected:
    BookNode* headNode;
    public:
    BookLinkedList();
    BookLinkedList(Book);
    void add(Book);
    void display();
    virtual bool compareBooks(Book, Book);
    bool containsBook(string);
};

#endif
