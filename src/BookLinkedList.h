#ifndef BOOKLINKED
#define BOOKLINKED

#include "BookNode.h"
#include "Book.h"
class BookLinkedList{
    protected:
    BookNode* headNode;
    virtual bool compareBooks(Book, Book);
    public:
    BookLinkedList();
    BookLinkedList(Book);
    void add(Book);
    void display();
    bool containsBook(string);
};

#endif
