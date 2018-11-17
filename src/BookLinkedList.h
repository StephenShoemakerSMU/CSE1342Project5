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
    virtual string toString();
    bool containsBook(string);
    bool isEmpty(){return headNode == nullptr;};
    int bookCount();
};

#endif
