
#ifndef LOAN
#define LOAN
#include "Book.h"
class BookOnLoan : public Book{
  private:
    string returnDate;
    string borrowerFName;
    string borrowerLName;
  public:
    BookOnLoan(Book, string, string, string);
    Book returnBook();

    string getReturnDate();
    string getBorrowerFName();
    string getBorrowerLName();

    void setReturnDate(string);
    void setBorrowerFName(string);
    void setBorrowerLName(string);

    void display();

    string toString();
};

#endif
