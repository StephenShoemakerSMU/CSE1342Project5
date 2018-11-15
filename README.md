Project 5 – Personal Library Manager
Due Date: Friday Nov 16 2018 at 11:59 pm properly submitted. 
Scenario
Dr. Jackson loves his books.  His office is filled with books, and they are all neatly organized on one shelf that circles the entirety of the office about 8 feet off the ground.  Now, Dr. Jackson is also very particular about organization.  All the books are organized from largest to smallest based size and number of pages.   He also enjoys loaning his books out to friends and colleagues but is fastidious about keeping track of who has what book and when it will be returned.  
He’s hired you to write a program that will read in his old system of managing his bookshelf and his personal book loans.  
Input
The input will come from a file and will be formatted as follows:
•	The first line of the file will contain a single integer n representing the number of input records each on a separate line. 
•	Each n input records will be formatted as one of three possible record types.  They are:
?	An Add Record: The first character of the line will be an A followed by the width in inches of the cover of the book, the height in inches of the cover of the book, the number of pages, the last name of the first author, the first name of the first author, and the title of the book. An example is:
		A 12 9 485 Smith John C++ For All
?	A Loan Record:  The first character of the line will be an L followed by the last name of the borrower, the first name of the borrower, the month of return, the day of month of return, and the year of return, and the title of the book. An example is:
		L Johnson Sally 12 01 18 C++ For All
?	A Return Record: The first character of the line will be an R followed by the title of the book. 
		R C++ For All
Your Task
Your program should maintain two lists of books: what is on the bookshelf, and what books are loaned out.  Further, the list of bookshelf books should be maintained in the same order as they would appear on the shelf (largest to smallest).  Book A is considered larger than Book B if the area of the cover of Book A is larger than the area of the cover of Book B.  If the covers are the same size, the Book A is larger than Book B if it has more pages.  The list of loaned books should be kept in the order of nearest return date.  
When a book is loaned out to a friend, it is moved from the bookshelf list to the loanedout list in proper order.  If/when it is returned, it is moved back to the bookshelf list in its proper position.  If an attempt is made to loan out a book that is already loaned out or doesn’t exist in the collection, you should print an error message (see Implementation Details below).
Output
After the entire input file has been read in and processed, write two output files:
1.	bookshelf.txt – a file containing all of the books that should be on the bookshelf in the order in which they would appear on the bookshelf (largest to smallest). The first line of the file should contain the number of books on the bookshelf.  
2.	booksOnLoan.txt – a file containing all of the books that are on loan in the order in which they are to be returned (soonest should be first).  The first line of the file should contain the number of books currently on loan. 
Sample Input and Output
Example booklist.txt file:
13
A 8 10 663 Thor Anau Who, What, and When
A 12 9 485 Smith John C++ for All
A 8 10 444 Simpson Bob The Python Way
L Reallyknow Idont 12 15 18 Who, What, and When
L Thompson Jan 12 01 18 The Python Way
A 12 9 301 Thor Anau Infinity and Beyond
A 11 8 599 Smith John Java Starter Edition
L Johnson Sally 12 01 18 C++ for All
L Johnson Susan 12 01 18 Infinity and Beyond
A 5 7 233 Johnson Susan An Apple A Day
A 5 8 333 Copperfiled Jane The Practice 
R C++ for All
L Grisham John 12 30 18 The Practice

Example bookshelf.txt file:
3
1. C++ for All by John Smith (12x9, 485 p)
2. Java Starter Edition by John Smith (11x8, 599 p)
3. An Apple A Day by Susan Johnson (5x7, 233 p)

Example booksOnLoan.txt file:
4
12/01/18
1. The Python Way borrowed by Jan Thompson
2. Infinity and Beyond borrowed by Susan Johnson
12/15/18
3. Who, What, and When borrowed by Idont Reallyknow
12/30/18
4. The Practice borrowed by John Grisham
Assumptions
1.	No two books will have the same name. 
2.	First and last names of authors or borrowers will not contain spaces
3.	No two books will have both the same size cover and the same number of pages
Implementation Requirements
•	Your implementation must be object oriented with at least three classes plus a main driver. At least one of those classes must be a Linked List class to manage lists of books.
•	Each class must be separated into interface (.h file) and implementation (.cpp file).
•	Exceptional Conditions:
?	If an attempt is made to loan out a book that is not in the library, print an error message to the terminal indicating the name of the book followed by NOT IN LIBRARY. 
?	If an attempt is made to loan out a book that is already on loan, print an error message to the terminal indicating the name of the book followed by ALREADY LOANED OUT
Code Formatting and Grading
•	https://s2.smu.edu/~etchison/cse1342/pguide.doc
