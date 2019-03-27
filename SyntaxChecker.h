/*
  James Romero
  ID: 2334232
  jaromero@chapman.edu
  CPSC 350-01
  Assignment 3
*/
#include <iostream>
using namespace std;


class SyntaxChecker {
public:
  SyntaxChecker() {}; //default constructor
  ~SyntaxChecker(); //Destructor

  SyntaxChecker() {}; //default constructor, left empty because there are no member variables to initalize
private:
  char getDelimiter(char c); //getDelimiter essentially finds the close delimiter match of a passed character

  bool DelimiterOpen(char c); //DelimiterOpen essentially verifies weather the character passed is a functional (open delimiter)
  bool DelimiterClosed(char c); // On the contrary "DelimiterClosed" verifies the character passed functional (close delimiter)
  bool DelimiterPair(char top, char pair); //DelimiterPair is used to verify a match pair of delimiter
  bool islanguage(char i, char x);// Verify programming language used



};



//Delimiter definition:
/*A delimiter is a sequence of one or more characters
used to specify the boundary between separate, independent
regions in plain text or other data streams.[1] An example
of a delimiter is the comma character, which acts as a field
delimiter in a sequence of comma-separated values.

Delimiters represent one of various means to specify
boundaries in a data stream. Declarative notation, for
example, is an alternate method that uses a length field
at the start of a data stream to specify the number of
characters that the data stream contains.[2]*/
