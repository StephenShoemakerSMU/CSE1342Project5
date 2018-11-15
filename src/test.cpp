#include "Book.h"
#include "ShelfLinkedList.h"
#include <iostream>

int main(){
  Book book1("A Game Of Thrones", "Goerge", "Martin", 100,100,500);
  Book book2("Clash of Kings", "Goerge", "Martin", 110,110, 400);
  Book book3("A Storm of Sword", "Goerge", "Martin", 400,400, 600);
  ShelfLinkedList shelf;
  shelf.add(book1);
  shelf.add(book2);
  shelf.add(book3);
  shelf.display();
}
