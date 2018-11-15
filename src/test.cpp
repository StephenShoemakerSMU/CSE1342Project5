#include "Book.h"
#include <iostream>

int main(){
  Book book1;
  Book book2("Storm Front", "Jim", "Butcher", 100, 50, 200);
  book1.display();
  book2.display();
  book2.loan("Stephen", "Shoemaker", 11,11,11);
  book2.display();
  book2.returnBook();
  book2.display();
}
