#include "SyntaxChecker.h"
#include <iostream>
using namespace std;



char Delimiters::getMatch(char c) //finds the close delimiter match to a passed character
{
  if(c == '(') //parentheses
  {
    return ')';
  }
  else if (c == '[') //square brackets
  {
    return ']';
  }
  else if (c == '{') //curly brackets
  {
    return '}';
  }
  else //if the passed character is not a valid open delimiter, the function just returns the passed character
  {
    return c;
  }
}

bool Delimiters::isOpenDelimiter(char c) //checks if the passed character is a valid open delimiter
{
  if(c == '(' || c == '[' || c == '{')
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Delimiters::isCloseDelimiter(char c) //checks if the passed character is a valid close delimiter
{
  if(c == ')' || c == ']' || c == '}')
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Delimiters::isMatch(char top, char pair) //checks if the two passed characters are a pair of delimiters
{
  if((top == '(' && pair == ')') || (top == '[' && pair == ']') || (top == '{' && pair == '}'))
  {
    return true;
  }
  else
  {
    return false;
  }
}
