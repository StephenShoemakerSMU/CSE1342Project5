//Stephen Shoemaker
//Library.cpp
//CSE 1342 Program 5
//11/16/18
//This is the definition for the library class
//This class manages a Shelf class and a Loan class and the communication
//between them and the driver file
//It also generates the textFiles for the output

#include "Library.h"
#include <iostream>
#include <sstream>

//Stephen Shoemaker
//Takes a book as an argument
//Adds a new book to the library
void Library::addBook(Book newBook){
  shelf.add(newBook);
}

//Stephen Shoemaker
//No paramaters
//Displays the library to console
//returns nothing
void Library::displayLibrary(){
  //Checking if there is data in the shelf
  if(!shelf.isEmpty()){
    cout << "Shelf Contents:" << endl;
    shelf.display();
  }
  //Checking if there is data in the loan
  if(!loan.isEmpty()){
    cout << "Loan Contents: " << endl;
    loan.display();
  }
}

//Stephen Shoemaker
//Takes the parameter of a bookName, Borrower NAme, and return date
//Checks out the book for the borrower and saves the return date
//Removes the book from the shelf and stores the information in Loan List
//returns nothing
void Library::checkOutBook(string bookName, string borrowerFName, string borrowerLName,
                            int returnMonth, int returnDay, int returnYear){
  //Checking if the book is even on the shelf
  if(!shelf.containsBook(bookName)){
    //checking if book is already loaned
    if(!loan.containsBook(bookName)){
      cout << bookName << " NOT IN LIBRARY" << endl;
    }else{
      cout << bookName << " ALREADY LOANED OUT" << endl;
    }
  }

  else{ //Book is on shelf
    //storing the book in this scope in order to pass it to loan
    Book bookLoaned = shelf.loanOut(bookName);//finding book

    //writing loan
    bookLoaned.loan(borrowerFName,borrowerLName,returnMonth, returnDay, returnYear);

    //adding loan to list
    loan.add(bookLoaned);
  }
}

//Stephen Shoemaker
//Takes a book name as argument
//returns nothing
//returns book to shelf it was loaned out
void Library::returnBook(string bookName){
  //Checking if book was loaned
  if(loan.containsBook(bookName)){
    //Taking loaned book and storing it to put on shelf
    Book bookReturned = loan.returnBook(bookName);
    //removing loan data from book
    bookReturned.returnBook();
    //putting book on shelf
    shelf.add(bookReturned);
  }
  else{ //This book wasn't loaned out properly
    cout << "Book not loaned" << endl;
  }
}

//Stephen Shoemaker
//no parameters
//This function takes a command file and processes each line
//The first character defines a command
//A is add
//L is loan
//R is return
//returns nothing
void Library::processBookList(string bookList){
  //Creating an input stream for the file
  ifstream inputFile(bookList);

  //Storing the curent line
  //This is the paramaters for the command and will be parsed
  string currLine = "";

  //Storing the amount of commands
  //Not sure if needed, but whatever
  int commandCount;
  inputFile >> commandCount;

  //Stores the command
  char command;
  getline(inputFile,currLine);
  while(inputFile.good()){

    if(command == 'A'){ //Adding if A
      addRecord(currLine);
    }else if(command == 'L'){//Loaning if L
      loanRecord(currLine);
    }else if(command == 'R'){//Returning if R
      returnRecord(currLine);
    }

    //storing the next command
    inputFile >> command;
    //storing the next paramaters for the command
    getline(inputFile, currLine);
  }

  //closing the input file
  inputFile.close();
}

//Stephen Shoemaker
//record string as parameter
//parses and runs the add record
//returns nothing
void Library::addRecord(string record){
  //clearing any leading spaces
  record.erase(0, record.find_first_not_of(' '));

  //using stringstream in order to parse command
  stringstream streamRecord(record);

  //Parameters for addCommand
  int width;
  int length;
  int pages;
  string fName;
  string lName;
  string bName;

  //Inserting single word paramaters
  streamRecord >> width >> length >> pages >> lName >> fName;

  //Had to sacrifice three goats to get this to work
  //Essentially passes the next word into nextStringInTitle and adds it to
  //bName.
  //Keep doing this until the end of streamRecord is reached
  //I feel there should be a better way to do this but if it ain't broke don't
  //fix it
  string nextStringInTitle;
  while(streamRecord.good()){ //looping through until end is reached
    streamRecord >> nextStringInTitle; //setting nextString to next string duh
    if(streamRecord.good()){//If the end wasn't reached
      bName += nextStringInTitle + " ";//add the string to the title
    }
  }

  //Creating a Book based on the parameters and adding it to the shelf
  Book newBook(bName, fName, lName, width, length, pages);
  addBook(newBook);
}

//Stephen Shoemkaer
//record String as paramater
//parses and runs the loan record
//returns nothing
void Library::loanRecord(string record){
  //clearing any leading spaces
  record.erase(0, record.find_first_not_of(' '));

  //using stringstream in order to parse command
  stringstream streamRecord(record);

  //Parameters for loanCommand
  string bName;
  string fName;
  string lName;
  int month;
  int day;
  int year;

  //Inserting single word paramaters
  streamRecord >> lName >> fName >> month >> day >> year;

  //Same algorithim as addRecord()
  //Had to sacrifice three goats to get this to work
  //Essentially passes the next word into nextStringInTitle and adds it to
  //bName.
  //Keep doing this until the end of streamRecord is reached
  //I feel there should be a better way to do this but if it ain't broke don't
  //fix it
  string nextStringInTitle;
  while(streamRecord.good()){
    streamRecord >> nextStringInTitle;
    if(streamRecord.good()){
      bName += nextStringInTitle + " ";
    }
  }
  //clearing any leading spaces from bName
  bName.erase(0, bName.find_first_not_of(' '));

  //Checking out the book based on commands paramaters
  checkOutBook(bName, fName, lName, month, day, year);
}


//Stephen Shoemaker
//record String as paramater
//runs a returnCommand based on the record
//returns nothing
void Library::returnRecord(string record){
  //clearing any leading spaces
  record.erase(0, record.find_first_not_of(' '));

  //using stringstream in order to parse command
  stringstream streamRecord(record);
  //paramaters
  //Same algorithim as addRecord()
  //Had to sacrifice three goats to get this to work
  //Essentially passes the next word into nextStringInTitle and adds it to
  //bName.
  //Keep doing this until the end of streamRecord is reached
  //I feel there should be a better way to do this but if it ain't broke don't
  //fix it
  string bName;
  string nextStringInTitle;
  while(streamRecord.good()){
    streamRecord >> nextStringInTitle;
    if(streamRecord.good()){
      bName += nextStringInTitle + " ";
    }
  }

  //clear leading spaces
  bName.erase(0, bName.find_first_not_of(' '));

  //returning the book
  returnBook(bName);
}

//Stephen Shoemaker
//no paramaters
//Creating the textFiles for shelf and loan
//returns nothing
void Library::produceTextFiles(){
  shelf.produceTextFile("bookshelf.txt");
  loan.produceTextFile("booksOnLoan.txt");
}
