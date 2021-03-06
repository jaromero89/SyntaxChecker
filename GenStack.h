/*
  James Romero
  ID: 2334232
  jaromero@chapman.edu
  CPSC 350-01
  Assignment 3
  Citation: Professor Rene Guzman protype from class, template class: www.cplusplus.com

*/

#include <iostream>
using namespace std;

template <typename T> /*Source: http://www.cplusplus.com/doc/oldtutorial/templates/*/
class GenStack //the class definition for a generic stack interface
{
public:
  GenStack(); //Default Constructor
  GenStack(int maxSize); //overloaded Constructor
  ~GenStack(); //Destructor


  int getSize() { return (top + 1); } //return size of the stack
  void push(T o); //adds the data to (top of stack)
  T pop(); //removes data from (top of stack)
  T peek(); //returns but does not remove element on top of stack

  bool isFull() { return (top == size - 1); } //checks if the stack is full
  bool isEmpty() { return (top < 0); } //checks if the stack is empty

  void resize(); //resizes the array that forms the basis of the stack

  int size; //keeps track on how many elements are inside
  int top; //the index of the top element of the stack

  T* myArray; //the array that forms the basis of the stack
};

class EmptyStackException //class definition for an exception that is thrown if the user attempts to interact with an empty stack
{
public:
  EmptyStackException(string message) : error_message(message) { } //constructor with initializer list
  string getErrorMessage() { return error_message; } //accessor that returns the error message
private:
  string error_message; //the error message associated with the error object
};

//out-of-class member functions for GenStack

template <typename T>
GenStack<T>::GenStack() //default constructor, creates a stack with size 100
{
  size = 100;
  top = -1;

  myArray = new T[100];
}

template <typename T>
GenStack<T>::GenStack(int maxSize) //constructor, creates a stack of the passed size
{
  size = maxSize;
  top = -1;

  myArray = new T[maxSize];
}

template <typename T>
GenStack<T>::~GenStack() //destructor
{
  delete[] myArray;
}

template <typename T>
void GenStack<T>::push(T o) //adds element to top of stack
{
  if(isFull()) //if the stack is full, the function resizes the array
  {
    resize();
  }

  myArray[++top] = o;
}

template <typename T>
T GenStack<T>::pop() //removes element from top of stack
{
  try //attempts to remove top element, throws exception if stack is empty
  {
    if(isEmpty())
      throw EmptyStackException("ERROR: Cannot pop something from an empty stack.");
    else
    {
      --top;
      return myArray[top + 1];
    }
  }
  catch(EmptyStackException& e) //if exception is thrown, an error message is printed to the console
  {
    cout << e.getErrorMessage() << endl;
  }
}

template <typename T>
T GenStack<T>::peek() //returns but does not remove element on top of stack
{
  try //attempts to view top element, throws exception if stack is empty
  {
    if(isEmpty())
      throw EmptyStackException("ERROR: Cannot peek() an empty stack.");
    else
    {
      return myArray[top];
    }
  }
  catch(EmptyStackException& e) //if exception is thrown, an error message is printed to the console
  {
    cout << e.getErrorMessage() << endl;
  }
}

template <typename T>
void GenStack<T>::resize() //resizes the array that forms the basis of the stack
{
  size = size * 2; //doubles the size of the array
  T* newArray = new T[size]; //allocates an array of the new doubled size

  for(int i = 0; i <= top; ++i) //copies all elements of the existing array to the new array
  {
    newArray[i] = myArray[i];
  }

  delete[] myArray; //deallocates the memory currently used by myArray
  myArray = newArray; //assigns the location of newArray to myArray
}
