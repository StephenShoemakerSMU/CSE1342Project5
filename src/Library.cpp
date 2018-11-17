#include "Library.h"
#include <iostream>


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
