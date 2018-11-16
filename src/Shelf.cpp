#include "Shelf.h"
//Stephen Shoemaker
//Takes Two books parameters
//Returns true if the first book goes before the second book by following Conditions
//1.Book 1 greater area
//2.Book 1 has equal area but more pages
//This function could probably be one line but this is easier to read
bool Shelf::compareBooks(Book book1, Book book2){
  //Checking Condition 1
  if(book1.getArea() > book2.getArea()){
    return true;
  }
  //Checking Condition 2
  else if(book1.getArea() == book2.getArea() && book1.getPages() > book2.getPages()){
    return true;
  }
  return false;
}


//Stephen Shoemaker
//Takes string parameter as book name
//Returns a pointer to the book if it in the list and removes it from the list
//Will print out NOT IN LIBRARY if the book is not on the shelf
BookNode* Shelf::loanOut(string bName){
  //checking if the the first node has the same name as the book
  if(headNode->getBook().getBookName() == bName){
    BookNode* output = headNode;
    headNode = headNode->getNextNode();
    return output;
  }

  //Looping through the rest of the list until book is found
  BookNode* currNode = headNode;
  while(currNode != nullptr && currNode->getNextNode()->getBook().getBookName() != bName){
    currNode = currNode-> getNextNode();
  }

  BookNode* output = currNode->getNextNode();
  currNode->setNextNode(currNode->getNextNode()->getNextNode());
  return output;

}
