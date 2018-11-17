//Stephen Shoemaker
//BookLinkedList.cpp
//CSE 1342 Project 5
//11/15/18
//This class is a linked List based around the bookNode class
//The BookLinkedList is dependent on it's subclasses compare function to properly add
//items to the list

#ifndef BOOKLINKED
#define BOOKLINKED

#include "BookNode.h"
#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
class BookLinkedList{
    //using protected instead of private because of two subclasses
  protected:
    BookNode* headNode;//starting node

    //this function compares books in order for them to be properly added
    //subclasses can create different compareBook functions to have
    //different sorts
    virtual bool compareBooks(Book, Book);
  public:
    BookLinkedList();//initializes an empty list
    BookLinkedList(Book);//initializes a list with one Book

    //adds a book to the list
    //keeps the list sorted based on compareBooks
    void add(Book);

    //couts the toString()
    void display();

    //outputs the list to a string
    //virtual because subclasses may adjust it
    virtual string toString();

    //checks if a book is in the class
    bool containsBook(string);

    //returns true if the list is empty
    bool isEmpty(){return headNode == nullptr;};

    //generates a count of books in the list
    int bookCount();

    //produces a textFile based on the toString
    void produceTextFile(string);
};

#endif
