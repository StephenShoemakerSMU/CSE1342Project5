#include "BookNode.h"

BookNode::BookNode(Book data){
  book = data;
  nextNode = nullptr;
}

BookNode * BookNode::getNextNode(){
  return nextNode;
}

void BookNode::setNextNode(BookNode* newNextNode){
  nextNode = newNextNode;
}

Book BookNode::getBook(){
  return book;
}
