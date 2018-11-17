#include "Book.h"
#include "Library.h"
//#include "Loan.h"
#include <iostream>

int main(){
  Book book1("A Game Of Thrones", "Goerge", "Martin", 100,100,500);
  Book book2("Clash of Kings", "Goerge", "Martin", 110,110, 400);
  Book book3("A Storm of Sword", "Goerge", "Martin", 400,400, 600);
  Book book4("APPLES", "Steve", "Shoemaker", 50, 200, 600);
  Library smithsonian;
  smithsonian.addBook(book3);
  smithsonian.addBook(book2);
  smithsonian.addBook(book1);
  smithsonian.addBook(book4);
  smithsonian.displayLibrary();



  smithsonian.checkOutBook("APPLES", "Steve", "Shoemaker", 10, 20, 80);
  smithsonian.checkOutBook("A Game Of Thrones", "Steve", "Shoemaker",10,20,80);

  smithsonian.displayLibrary();

  //cout << "Shelf Contains Apples: " << shelf.containsBook("APPLES");
}
