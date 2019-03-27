#include "GenStack"
#include "SyntaxChecker.h"
#include <iostream>
using namespace std;

class File
{
public:
  file();//constructor
  ~File();//destructor

  void file();
  ifstream input_file; //input file stream
  string filepath; //where the file is located
  string line; // initializer: file reading "line"
  char choice; //used to store user's choice
  bool read_in = true; //allows file checking to be repeated
  bool valid_file = true; //sets up the necessary break clauses for nested loops
  int index = 1; //line count of the code

  GenStack<char> s(100); //GenStack which was developed in class
  Delimiters d; //initializes a Delimiters object

};
