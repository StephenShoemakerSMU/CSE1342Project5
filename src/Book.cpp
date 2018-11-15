//Stephen Shoemaker
//Book.cpp
//CSE 1342 PROJECT 5
//11/15/18
//This code is the definitions for the Book class
//The book class stores data for books either on loan or on shelf
#include "Book.h"
#include <stdio.h>
#include <iostream>
//#include <string.h>
//#include <string>
using namespace std;

//Public class functions for books not on loan

//Stephen Shoemaker
//Zero-Arg Book Constructor
//Creates a Book class with defualt values
Book::Book(){
  bookName = "";
  authorFName = "";
  authorLName = "";
  width = 0;
  height = 0;
  pages = 0;
  onLoan = false;
}

//Stephen Shoemaker
//Takes book name, author name, cover width and length, and page count
//Creates a book class with values equal to parameters
Book::Book(string initialBookName, string initialAuthorFName, string initialAuthorLName, int initialWidth, int initialHeight, int initialPages){
  bookName = initialBookName;
  authorFName = initialAuthorFName;
  authorLName = initialAuthorLName;
  width = initialWidth;
  height = initialHeight;
  pages = initialPages;
  onLoan = false;
}


//Book On Loan getters and setters

//Stephen Shoemaker
//Takes no arguments
//returns bookName
string Book::getBookName(){
  return bookName;
}

//Stephen Shoemaker
//Takes no arguments
//returns authorFName
string Book::getAuthorFName(){
  return authorFName;
}

//Stephen Shoemaker
//Takes no arguments
//returns authorLNAme
string Book::getAuthorLName(){
  return authorLName;
}

//Stephen Shoemaker
//takes no arguments
//returns width
int Book::getWidth(){
  return width;
}

//Stephen Shoemaker
//takes no arguments
//returns height
int Book::getLength(){
  return length;
}

//Stephen Shoemaker
//takes no arguments
//calculates and returns area
int Book::getArea(){
  return width*length;
}

//Stephen Shoemaker
//Takes String arguments
//sets book name to parameter
//returns nothing
void Book::setBookName(string newBookName){
  bookNAme = newBookName;
}

//Stephen Shoemaker
//Takes String arguments
//sets authorFName to parameter
void Book::setAuthorFName(string newAuthorFName){
  authorFName = newAuthorFName;
}

//Stephen Shoemaker
//Takes String arguments
//sets authorLName to parameter
//returns nothing
void Book::setAuthorLName(string newAuthorLName){
  authorLNAme = newAuthorLName;
}

//Stephen Shoemaker
//takes int argument
//sets width to parameter
//returns nothing
void Book::setWidth(int newWidth){
  width = newWidth;
}

//Stephen Shoemaker
//takes int argument
//sets height to parameter
//returns nothing
void Book::setHeight(int newHeight){
  height = newHeight;
}

//Stephen Shoemaker
//takes two int arguments
//sets width and heights to parameters
//returns nothing
void Book::setWidthAndLength(int newWidth, int newHeight){
  width = newWidth;
  height = newHeight;
}

//Stephen Shoemaker
//takes one int argument
//sets pages to parameter
//returns nothing
void Book::setPages(int newPages){
  pages = newPages;
}

//Book on Loan getters and setters

//Stephen Shoemaker
//takes no arguments
//returns the value for if book is on loan
bool Book::isOnLoan(){
  return onLoan;
}

//Stephen Shoemaker
//takes no arguments
//returns the value of the Borrowers first name
string Book::getBorrowerFName(){
  return borrowerFName;
}

//Stephen Shoemaker
//takes no arguments
//returns the value of the Borrowers last name
string Book::getBorrowerLName(){
  return borrowerLName;
}

//Stephen Shoemaker
//takes no arguments
//returns the string value of date of return
string Book::getDateOfReturn(){
  return to_string(returnMonth) + "/" + to_string(returnDay) + "/" + to_string(returnYear);
}

//Stephen Shoemaker
//takes no arguments
//returns day of return
int Book::getDayOfReturn(){
  return returnDay;
}

//Stephen Shoemaker
//takes no arguments
//returns month of return
int Book::getMonthOfReturn(){
  return returnMonth;
}

//Stephen Shoemaker
//takes no arguments
//returns year of return
int Book::getYearOfReturn(){
  return returnYear;
}

//Stephen Shoemaker
//takes bool argument
//sets loan value to argument
//returns nothing
void Book::setIsOnLoan(bool newLoanValue){
  onLoan = newLoanValue;
}

//Stephen Shoemaker
//takes string argument
//sets borrowerLName to argument
//returns nothing
void Book::setBorrowerLName(string newBorrowerLName){
  borrowerLname = newBorrowerLName;
}

//Stephen Shoemaker
//takes string argument
//sets borrowerFName to argument
//returns nothing
void Book::setBorrowerFName(string newBorrowerFName){
  borrowerFName = newBorrowerFName;
}

//Stephen Shoemaker
//takes int argument
//sets dayOfReturn to argument
//returns nothing
void Book::setDayOfReturn(int newDay){
  dayOfReturn = newDay;
}

//Stephen Shoemaker
//takes int argument
//sets monthOfReturn to argument
//returns nothing
void Book::setMonthOfReturn(int newMonth){
  monthOfReturn = newMonth;
}

//Stephen Shoemaker
//takes int argument
//sets yearOfReturn to argument
//returns nothing
void Book::setYearOfReturn(int newYear){
  yearOfReturn = newYear;
}

//END OF GETTERS AND SETTERS

//Data display functions

//Stephen Shoemaker
//no arguments
//This function couts the toString function
//returns nothing
void Book::display(){
  cout << toString() << endl;
}

//Stephen Shoemaker
//takes no arguments
//This function returns the appropriate string based on wether the book is onLoan or not
string Book::toString(){
  if(onLoan){
    return toStringOnLoan();
  }
  else {
    return toStringOnShelf();
  }

  cout << "in Book::toString and reached end of toString" << endl;
  return "ERROR: REACHED END OF TOSTRING";
}

//Stephen Shoemaker
//No arguments
//This function returns a string based on the data for it being on the shelf
string Book::toStringOnShelf(){
  return bookName + " by " + authorFName + " " + authorLName +
          " ( " + to_string(width) + "x" + to_string(height) +
          " " + to_string(pages) + " p)";
}
