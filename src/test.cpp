#include "Book.h"
#include <iostream>

int main(){
  Book book1;
  Book book2("Storm Front", "Jim", "Butcher", 100, 50, 200);
  std::cout << book1.toStringOnShelf() << std::endl << book2.toStringOnShelf() << std::endl;
}
