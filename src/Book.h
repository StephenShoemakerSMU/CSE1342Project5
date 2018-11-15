//Stephen Shoemaker
//Book.h
//CSE 1342 Project 5
//11/15/18
//This class is to represent books on a shelf in a library database
//It will contain size, name, author name, and pages
//Also will store loan information such as borrower name and return date

#ifndef BOOK
#define BOOK

#include <string>
using namespace std;
class Book{
  private:

    //all books have these
    string bookName;
    string authorFName;
    string authorLName;
    int width;
    int height;
    int pages;


    //This is the data that is stored if the book is on Loan
    bool onLoan;
    string borrowerLName;
    string borrowerFName;
    int returnDay;
    int returnMonth;
    int returnYear;

    //different output depending if onLoan or not
    string toStringOnShelf();
    string toStringOnLoan();

    string returnDateAsString();

    //clears returnDates when book is returned
    void clearReturnDates();
  public:
    Book();
    Book(string ,string ,string, int, int , int );

    //getters and setters for all books
    string getBookName();
    string getAuthorFName();
    string getAuthorLName();
    int getWidth();
    int getHeight();
    int getPages();
    int getArea();

    void setBookName(string);
    void setAuthorFName(string);
    void setAuthorLName(string);
    void setWidth(int);
    void setHeight  (int);
    void setWidthAndLength(int,int);
    void setPages(int);

    //getters and setters for books on loan
    bool isOnLoan();
    string getBorrowerLName();
    string getBorrowerFName();
    string getDateOfReturn();
    int getDayOfReturn();
    int getMonthOfReturn();
    int getYearOfReturn();

    void setIsOnLoan(bool);
    void setBorrowerLName(string);
    void setBorrowerFName(string);
    void setDayOfReturn(int);
    void setMonthOfReturn(int);
    void setYearOfReturn(int);


    //outputs the toString to console
    void display();

    //returns the toString depending if the books on loan or on shelf
    string toString();

    //sets onLoan to false and clears the values for if onLoan
    void returnBook();

    //Loans a book out to a certain person
    void loan(string, string, int, int, int);

};

#endif
