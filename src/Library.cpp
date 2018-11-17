#include "Library.h"
#include <iostream>

Library::Library(){
  shelf = Shelf();
}

void Library::addBook(Book newBook){
  shelf.add(newBook);
}

void Library::displayLibrary(){
  cout << "Shelf Contents:" << endl;
  shelf.display();

  cout << "Loan Contents: " << endl;
  loan.display();
}

void Library::checkOutBook(string bookName, string borrowerFName, string borrowerLName, int returnMonth, int returnDay, int returnYear){
  Book bookLoaned = shelf.loanOut(bookName);
  bookLoaned.loan(borrowerFName,borrowerLName,returnMonth, returnDay, returnYear);
  loan.add(bookLoaned);
}
