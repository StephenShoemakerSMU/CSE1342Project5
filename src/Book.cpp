#include "Book.h"
#include <stdio.h>
//#include <string.h>
//#include <string>
using namespace std;
Book::Book(){
  bookName = "";
  authorFName = "";
  authorLName = "";
  width = 0;
  height = 0;
  pages = 0;
}

Book::Book(string initialBookName, string initialAuthorFName, string initialAuthorLName, int initialWidth, int initialHeight, int initialPages){
  bookName = initialBookName;
  authorFName = initialAuthorFName;
  authorLName = initialAuthorLName;
  width = initialWidth;
  height = initialHeight;
  pages = initialPages;
}

string Book::toString(){
  return bookName + " by " + authorFName + " " + authorLName + " ( " + to_string(width) + "x" + to_string(height) + " " + to_string(pages) + " p)";
}
