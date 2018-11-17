#include "Loan.h"
//Stephen Shoemaker
//BookLinkedList subclass to resemble a linked list of loaned books


//Stephen Shoemaker
//Takes two parameters
//Returns true if the first book has an eariler return date than the second books
//Could be one line but this is more readable
bool Loan::compareBooks(Book book1, Book book2){
  if(book1.getYearOfReturn() != book2.getYearOfReturn()){
    return book1.getYearOfReturn() < book2.getYearOfReturn();
  }
  if(book1.getMonthOfReturn() != book2.getMonthOfReturn()){
    return book1.getMonthOfReturn() < book2.getMonthOfReturn();
  }
  if(book1.getDayOfReturn() != book2.getDayOfReturn()){
    return book1.getDayOfReturn() != book2.getDayOfReturn();
  }
  return false;
}

//Stephen Shoemaker
//Takes parameter as book name
//Only works if book is in list
//returns the book if is in the list and removes it from loan
Book Loan::returnBook(string bName){
  //checking if the the first node has the same name as the book
  if(headNode->getBook().getBookName() == bName){
    BookNode* output = headNode;
    headNode = headNode->getNextNode();
    return output->getBook();
  }

  //Looping through the rest of the list until book is found
  BookNode* currNode = headNode;
  while(currNode != nullptr && currNode->getNextNode()->getBook().getBookName() != bName){
    currNode = currNode-> getNextNode();
  }

  BookNode* output = currNode->getNextNode();
  currNode->setNextNode(currNode->getNextNode()->getNextNode());
  return output->getBook();
}
