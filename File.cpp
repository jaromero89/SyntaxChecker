#include "File.h"
#include "GenStack.h"
#include "SyntaxChecker.h"
#include <iostream>
using namespace std;

void File::file()
{
while(read_in)
{
  cout << "Please enter your file: ";
  cin >> filepath;

  input_file.open(filepath);

  if( input_file.is_open() )
  {
    while( getline(input_file, line) )
    {
      for(int i = 0; i < line.length(); ++i)
      {
        if(d.DelimiterOpen(line[i])) //If statement used to see if if the character is an open delimiter
        {
          s.push(line[i]); //pushes the open delimiter to the top of the stack
        }

        if(d.DelimiterClosed(line[i])) //if statement used to check if the character is a close delimiter
        {
          if(s.isEmpty()) //see if the stack is empty
          {
            cout << "Error, Line " <<
            index << ": Closing " <<
            line[i] <<
            " with no matching opener. " << endl;
            valid_file = false; //sets up break out of while(getline) loop
            break; //breaks out of for loop
          }
          else if(d.DelimiterPair(s.peek(), line[i])) //checks if the close delimiter matches the open delimiter at the top of the stack
          {
            s.pop(); //removes the top of the stack if the match is correct
          }
          else //if not a match, the location of the error is printed
          {
            cout << "Error, Line " << index << ": Expected " << d.getMatch(s.peek()) << " but found " << line[i] << " instead." << endl;
            valid_file = false; //sets up break out of while(getline) loop
            break; //breaks out of for loop
          }
        }
      }
      if(!valid_file)
      {
        read_in = false; //negates condition for while(read_in) loop
        break; //breaks out of while(getline)
      }
      else
      {
        ++index; //increments line count
      }
    }
    if(valid_file) //this clause only happens if there wasn't an early termination of the above loop
    {
      if(!s.isEmpty()) //checks if the stack still has delimiters in it
      {
        cout << "Error, end of file: Missing " << d.getMatch(s.peek()) << endl;
        read_in = false; //negates condition for while(read_in) loop
      }
      else
      {
        cout << " No delimiter errors have been found." << endl;
        cout << "Would you like to check another file? Enter 'Y' for yes and 'N' for no: ";
        cin >> answer;

        if(toupper(answer) == 'N') //if user input no
        {
          read_in = false; //negates condition for while(read_in) loop
          cout << "Exiting program. " << endl;
        }
        else if(toupper(answer) != 'Y') //if user did not enter a valid input
        {
          read_in = false; //negates condition for while(read_in) loop
          cout << "Invalid input. Exiting program. " << endl;
        }
      }
    }
    input_file.close();
  }
  else //if the file could not be opened
  {
    cout << "File could not be opened. Please try again." << endl;
  }
}
}
