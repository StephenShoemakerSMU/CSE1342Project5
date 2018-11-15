#include "BookOnLoan.h"

BookOnLoan::BookOnLoan(Book bookOnShelf, string returnDate, string borrowerFName, string borrowerLname){
  Book(bookOnShelf.getBookName(), bookOnShelf.getAuthorFName(), bookOnShelf.getAuthorLName(), bookOnShelf.getWidth(), bookOnShelf.getHeight(), bookOnShelf.getPages());
  returnDate = returnDate;
  borrowerFName = borrowerFName;
  borrowerLName = borrowerLName;
}

Book BookOnLoan::returnBook(){
  Book output = Book(bookName, authorFName, authorLName, width, height, pages);
  delete this;
  return output;
}
