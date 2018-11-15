#include "Book.h"
#include <iostream>

int main(){
  Book book1;
  Book book2("Storm Front", "Jim", "Butcher", 100, 50, 200);
  book1.display();
  book2.display();
}
