#include "Book.h"
#include "Library.h"
//#include "Loan.h"
#include <iostream>

int main(){
  Library smithsonian;
  smithsonian.processBookList("BookList.txt");
  smithsonian.produceTextFiles();
}
