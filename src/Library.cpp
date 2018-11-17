#include "Library.h"
#include <iostream>
#include <sstream>


void Library::addBook(Book newBook){
  shelf.add(newBook);
}

void Library::displayLibrary(){
  if(!shelf.isEmpty()){
    cout << "Shelf Contents:" << endl;
    shelf.display();
  }

  if(!loan.isEmpty()){
    cout << "Loan Contents: " << endl;
    loan.display();
  }
}

void Library::checkOutBook(string bookName, string borrowerFName, string borrowerLName, int returnMonth, int returnDay, int returnYear){
  if(!shelf.containsBook(bookName)){
    if(!loan.containsBook(bookName)){
      cout << bookName << " NOT IN LIBRARY" << endl;
    }
    else{
      cout << bookName << " ALREADY LOANED OUT" << endl;
    }
  }
  else{
    Book bookLoaned = shelf.loanOut(bookName);
    bookLoaned.loan(borrowerFName,borrowerLName,returnMonth, returnDay, returnYear);
    loan.add(bookLoaned);
  }
}

void Library::returnBook(string bookName){
  if(loan.containsBook(bookName)){
    Book bookReturned = loan.returnBook(bookName);
    bookReturned.returnBook();
    shelf.add(bookReturned);
  }
  else{
    cout << "Book not loaned" << endl;
  }
}

void Library::processBookList(string bookList){
  ifstream inputFile(bookList);
  string currLine = "";
  int commandCount;
  inputFile >> commandCount;
  char command;
  getline(inputFile,currLine);
  while(inputFile.good()){

    if(command == 'A'){
      addRecord(currLine);
    }else if(command == 'L'){
      loanRecord(currLine);
    }else if(command == 'R'){
      returnRecord(currLine);
    }
    command;
    inputFile >> command;
    getline(inputFile, currLine);
  }
  inputFile.close();
}

void Library::addRecord(string record){
  record.erase(0, record.find_first_not_of(' '));
  stringstream streamRecord(record);
  //cout << record << endl;
  int width;
  int length;
  int pages;
  string fName;
  string lName;
  string bName;
  streamRecord >> width >> length >> pages >> lName >> fName;
  string nextStringInTitle;
  while(streamRecord.good()){
    streamRecord >> nextStringInTitle;
    if(streamRecord.good()){
      bName += nextStringInTitle + " ";
    }
  }

  //cout << "OUTPUTTING CORRECT hopefully" << endl;
  //cout << bName << " by " << fName << " " << lName << "( " << width << "x" << length << " " << pages << "p)" << endl;
  Book newBook(bName, fName, lName, width, length, pages);
  addBook(newBook);
}

void Library::loanRecord(string record){
  record.erase(0, record.find_first_not_of(' '));
  stringstream streamRecord(record);
  string bName;
  string fName;
  string lName;
  int month;
  int day;
  int year;
  streamRecord >> lName >> fName >> month >> day >> year;
  string nextStringInTitle;
  while(streamRecord.good()){
    streamRecord >> nextStringInTitle;
    if(streamRecord.good()){
      bName += nextStringInTitle + " ";
    }
  }
  bName.erase(0, bName.find_first_not_of(' '));
  checkOutBook(bName, fName, lName, month, day, year);
}

void Library::returnRecord(string record){
  record.erase(0, record.find_first_not_of(' '));
  stringstream streamRecord(record);
  string bName;
  string nextStringInTitle;
  while(streamRecord.good()){
    streamRecord >> nextStringInTitle;
    if(streamRecord.good()){
      bName += nextStringInTitle + " ";
    }
  }
  bName.erase(0, bName.find_first_not_of(' '));
  returnBook(bName);
}

void Library::produceTextFiles(){
  shelf.produceTextFile("bookshelf.txt");
  loan.produceTextFile("booksOnLoan.txt");
}
