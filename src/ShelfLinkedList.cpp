#include "ShelfLinkedList.h"

//Stephen Shoeamker
//Zero-Arg Constructor
//Creates a new ShelfLinkedList
ShelfLinkedList::ShelfLinkedList(){
  headNode = nullptr;
}

//Stephen Shoemaker
//Takes a book as initial argument
//Creates a new Shelf Linked List with the first node equalling initialBook
ShelfLinkedList::ShelfLinkedList(Book initialBook){
  headNode = new BookNode(initialBook);
}

//Stephen Shoemaker
//Takes a book as parameter
//Adding a book to the shelf, adds to the end for now
void ShelfLinkedList::add(Book newBook)
    {
        if(headNode == nullptr){
            headNode = new BookNode(newBook);
        }
        else{
          BookNode * curr = headNode;
          while(curr->getNextNode() != nullptr){
            curr = curr->getNextNode();
          }
          curr->setNextNode( new BookNode(newBook));
        }
    }

//Stephen Shoemaker
//Takes no paramters
//Displays the content of the list
void ShelfLinkedList::display(){
  BookNode * curr = headNode;
  while(curr!=nullptr){
    curr->getBook().display();
    curr = curr->getNextNode();
  }
}
