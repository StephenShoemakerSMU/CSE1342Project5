//Stephen Shoemaker
//Book class Header
//This class is to represent books on a shelf in a library database
//It will contain size, name, author name, and pages

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


    //fill these if on loan
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
    void setLength(int);
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
    void setDateOfReturn(string)


    void display();

    string toString();



};

#endif
