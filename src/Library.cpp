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
}

void Library::checkOutBook(string bookName, string borrowerFName, string borrowerLName, int returnMonth, int returnDay, int returnYear){
  Book bookLoaned = shelf.loanOut(bookName);
  std::cout << "Loaned out: " << bookLoaned.toString() << std::endl;
  std::cout << "Shelf Contents: " << std::endl;
  shelf.display();
}
