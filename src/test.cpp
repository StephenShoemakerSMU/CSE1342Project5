#include "Book.h"
#include "BookLinkedList.h"
#include "Shelf.h"
//#include "Loan.h"
#include <iostream>

int main(){
  Book book1("A Game Of Thrones", "Goerge", "Martin", 100,100,500);
  Book book2("Clash of Kings", "Goerge", "Martin", 110,110, 400);
  Book book3("A Storm of Sword", "Goerge", "Martin", 400,400, 600);
  Book book4("APPLES", "Steve", "Shoemaker", 50, 200, 600);
  Shelf shelf;
  shelf.add(book3);
  shelf.add(book2);
  shelf.add(book1);
  shelf.add(book4);
  shelf.display();

  cout << "Shelf Contains Apples: " << shelf.containsBook("APPLES") << endl;

  cout << endl << "Loaning out APPLES" << endl;

  shelf.loanOut("APPLES");
  shelf.display();

  cout << "Shelf Contains Apples: " << shelf.containsBook("APPLES");
}
