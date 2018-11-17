//Stephen Shoemaker
//BookNode.h
//CSE 1342 Program 5
//11/15/18
//This class is a BookNode for a linked List
//it is essentially a book and a pointer to the next book

#include "BookNode.h"

//creates a node based with the book as data
BookNode::BookNode(Book data){
  book = data;
  nextNode = nullptr;
}

//Stephen Shoemaker
//returns the next node
BookNode * BookNode::getNextNode(){
  return nextNode;
}

//Stephen Shoemaker
//takes a node as an argument
//sets the nextNode to the argument
void BookNode::setNextNode(BookNode* newNextNode){
  nextNode = newNextNode;
}

//Stephen Shoemaker
//returns the value of BookNode
Book BookNode::getBook(){
  return book;
}
