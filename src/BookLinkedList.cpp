#include "BookLinkedList.h"
#include <iostream>

//Stephen Shoeamker
//Zero-Arg Constructor
//Creates a new BookLinkedList
BookLinkedList::BookLinkedList(){
  headNode = nullptr;
}

//Stephen Shoemaker
//Takes a book as initial argument
//Creates a new Book Linked List with the first node equalling initialBook
BookLinkedList::BookLinkedList(Book initialBook){
  headNode = new BookNode(initialBook);
}

//Stephen Shoemaker
//Takes a book as parameter
//Adding a book to the Book, adds to the end for now
void BookLinkedList::add(Book newBook)
    {
        if(headNode == nullptr){
            headNode = new BookNode(newBook);
        }
        else if (compareBooks(newBook, headNode->getBook())) {
            BookNode *tmp = new BookNode(newBook);
            tmp->setNextNode(headNode);
            headNode = tmp;
        }
        else{
          BookNode * curr = headNode;
          while(curr->getNextNode()!=nullptr && !compareBooks(newBook, curr->getNextNode()->getBook())){
            curr = curr->getNextNode();
          }
          BookNode *tmp = new BookNode(newBook);
          tmp->setNextNode(curr->getNextNode());
          curr->setNextNode(tmp);
        }
    }

//Stephen Shoemaker
//Takes no paramters
//Displays the content of the list
void BookLinkedList::display(){
  cout << toString();
}

//Stephen Shoemaker
//This function is a placeholder for derived classes
//Loan linked list and Shelf will have differenct comparison functions
//If this was java I would make the function definition abstract but don't
//know cpp equivalent
bool BookLinkedList::compareBooks(Book b1, Book b2){
  std::cout << "THIS SHOULD NOT BE CALLED";
  return true;
}


bool BookLinkedList::containsBook(string bookName){
  BookNode* curr = headNode;
  while(curr!=nullptr){
    if(curr->getBook().getBookName() == bookName){
      return true;
    }
    curr= curr->getNextNode();
  }
  return false;
}

string BookLinkedList::toString(){
  BookNode * curr = headNode;
  string output = to_string(bookCount()) + "\n";
  int bookCount = 1;
  while(curr!=nullptr){
    output += to_string(bookCount) + ". " + curr->getBook().toString();
    output += "\n";
    bookCount++;
    curr = curr->getNextNode();
  }
  return output;
}

int BookLinkedList::bookCount(){
  int output = 0;
  BookNode* curr = headNode;
  while(curr != nullptr){
    output++;
    curr= curr->getNextNode();
  }
  return output;
}
