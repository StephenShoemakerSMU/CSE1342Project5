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
    string bookName;
    string authorFName;
    string authorLName;
    int width;
    int height;
    int pages;
  public:
    Book();
    Book(string ,string ,string, int, int , int );

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

    void display();

    string toString();

};

#endif
