//Stephen Shoemaker
//main.cpp
//11/17/18
//This is the main driver for program 5
//The program is a book management system
//It stores the books in library and the books loaned out

//The program features linked lists extensively
//The functions Utilizes a bookLinkedList class that stores the books
//bookLinkedList is never itself called but is instead derived by
//Shelf and Loan that differ in small ways
//Their key difference is how the compare books which leads to different sorting
//Shelf is sorted by size
//Loan is stored by return date

//The Library class manages the interactions between Shelf and Loan and passes
//books betweem them
//Library also processes commands from a textFile and excecutes them
//The commands are simple, add a book to the shelf, loan out a book, and
//return a book to the shelf from loan

//The Library class also generates the text Files bookshelf and booksOnLoan

#include "Library.h"
//#include "Loan.h"
#include <iostream>

int main(){
  Library smithsonian;
  smithsonian.processBookList("BookList.txt");
  smithsonian.produceTextFiles();

  return 0;
}
