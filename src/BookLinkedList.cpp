//Stephen Shoemaker
//BookLinkedList.cpp
//CSE 1342 Project 5
//11/15/18
//This class is a linked List based around the bookNode class
//The BookLinkedList is dependent on it's subclasses compare function to properly add
//items to the list

#include "BookLinkedList.h"


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
        //If the list is empty, create a new Node and add the first Book
        if(headNode == nullptr){
            //setting headNode to the new book
            headNode = new BookNode(newBook);
        }
        //Checking if the node after the headNode is where the Book Should go
        else if (compareBooks(newBook, headNode->getBook())) {
            //tmp stores the node for the new book
            BookNode *tmp = new BookNode(newBook);
            //setting the next node for temp to curr next node
            tmp->setNextNode(headNode);
            //setting curr next node to tmp
            headNode = tmp;
        }
        //Checking if the book should after the first two nodes
        else{
          //This Node keeps track of where the whileLoop is looking
          BookNode * curr = headNode;
          //Keep looking until the book should go after the current Node
          //Or until the end of the list is reacherd
          while(curr->getNextNode()!=nullptr && !compareBooks(newBook, curr->getNextNode()->getBook())){
            curr = curr->getNextNode();
          }

          //tmp stores the node for the new book
          BookNode *tmp = new BookNode(newBook);
          //setting the next node for temp to curr next node
          tmp->setNextNode(curr->getNextNode());
          //setting curr next node to tmp
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

//Stephen Shoemaker
//This function takes a book name as an argument
//this function checks if the bookName is in the list
//returns true if it is in the list
bool BookLinkedList::containsBook(string bookName){
  //checking every node, starting with the headNode for the bookName
  BookNode* curr = headNode;

  //looping through until end of list is reached
  while(curr!=nullptr){
    //if the name is found return
    if(curr->getBook().getBookName() == bookName){
      return true; //return true and exit loop
    }

    //moving on to the next node
    curr= curr->getNextNode();
  }

  //Name not found so returning string
  return false;
}


//Stephen Shoemaker
//no arguments
//creates the output string for the whole list and returns it
//returns the string
string BookLinkedList::toString(){
  //starting at the first node
  BookNode * curr = headNode;

  //beginning the output string and adding the count of numbers in the list
  string output = to_string(bookCount()) + "\n";

  //counting the books in the list to append the number to the beginiing
  int bookCount = 1;

  //looping through until end of list
  while(curr!=nullptr){
              //<bookCount>. <book.toString()>
    output += to_string(bookCount) + ". " + curr->getBook().toString() + "\n";

    bookCount++;//incrementing the book
    //Moving on to next node
    curr = curr->getNextNode();
  }

  //Returning the string
  return output;
}

//Stephen Shoemaker
//no arguments
//returns the amount of books in the linked list
int BookLinkedList::bookCount(){
  //stores the count of books
  int output = 0;
  //beginning with the first node
  BookNode* curr = headNode;
  //Looping until nullptr
  while(curr != nullptr){
    //increasing the count
    output++;
    //moving to nextNode
    curr= curr->getNextNode();
  }

  //returning output
  return output;
}

//Stephen Shoemaker
//no arguments
//generates an output file equivalent to the toString function
void BookLinkedList::produceTextFile(string fileName){
  ofstream outputFile; //File writer
  outputFile.open(fileName); //opening or creating a file named fileName
  outputFile << toString();//adding the toString to the file
  outputFile.close();//saving the file
}
