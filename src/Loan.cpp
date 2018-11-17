//Stephen Shoemaker
//Loan.cpp
//CSE 1342 Program 5
//11/16/18
//BookLinkedList subclass to resemble a linked list of loaned books
//Is sorted by return date
//Displayed by return date

#include "Loan.h"



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
    return book1.getDayOfReturn() < book2.getDayOfReturn();
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
    //setting output to the firstNode
    BookNode* output = headNode;

    //setting headNode to the next Node
    headNode = headNode->getNextNode();

    //returning the oldHeadNode
    return output->getBook();
  }

  //Looping through the rest of the list until book is found
  BookNode* currNode = headNode;

  //Checking if the currNode is not null
  //Also checking if the nextNode has the same name as bookNAme
  while(currNode != nullptr && currNode->getNextNode()->getBook().getBookName() != bName){
    //Moving to the next node
    currNode = currNode-> getNextNode();
  }

  //setting the output to the node after currNode
  BookNode* output = currNode->getNextNode();

  //setting currNode the node after its next node
  currNode->setNextNode(currNode->getNextNode()->getNextNode());

  //returning output's book
  return output->getBook();
}

//Stephen Shoemaker
//Takes no paramater
//Returns a string sorted by return date
//Books are clumped by date
string Loan::toString(){
  //stores the currentDate of the current clump of loans
  string currDate = "";

  //starting at the currentNode
  BookNode * curr = headNode;

  //starting an output string
  //initializing it to <bookCount>
  string output = to_string(bookCount()) + "\n";

  //different from bookCount()
  //stores the current count of books including the currentBook
  int bookCount = 1;

  //Looping until nullptr is reached
  while(curr != nullptr){

    //If a newDate is found append it to the string and add a new line
    if(currDate != curr->getBook().dateToString()){
      currDate = curr->getBook().dateToString();
      output += currDate + "\n";
    }

    //adding bookCount and the book string to the output
    output += to_string(bookCount) + ". " + curr->getBook().toString() + "\n";

    //incrementing bookCount
    bookCount++;

    //moving on to the next node
    curr = curr->getNextNode();
  }

  //returning the output
  return output;
}
