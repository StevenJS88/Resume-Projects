//---------------------------------------------------------------------
// Name:    Steven Storkson
// Project: Reverse Polish Notation Evaluator with Queue and Stack.
// Purpose: This header file shows the methods and private data members
//          that will be implemented in the .cpp implementation file.
//---------------------------------------------------------------------
#ifndef STACK_H
#define	STACK_H

//#define TESTING_STACK
#ifdef TESTING_STACK
   #include <iostream>
   using namespace std;
#endif

const int MAXSTACK = 80;
typedef float StackInfoType;
//---------------------------------------------------------------------
// Stack class data structure for storing numeric values
//---------------------------------------------------------------------
class Stack 
{
public:
   //---------------------------------------------------------------------
   // Stack constructor
   //---------------------------------------------------------------------
   Stack();
   
   //---------------------------------------------------------------------
   // Checks if Top is equal to Zero;
   //---------------------------------------------------------------------
   bool isEmpty();
   
   //---------------------------------------------------------------------
   // Checks if the array elements is of length MAXSTACK
   //---------------------------------------------------------------------
   bool isFull();
   
   //---------------------------------------------------------------------
   // Adds a StackInfoType number to the elements array
   //---------------------------------------------------------------------
   void push(StackInfoType num);
   
   //---------------------------------------------------------------------
   // Returns the StackInfoType number at the top of the stack
   //---------------------------------------------------------------------
   StackInfoType pop();
   
   //---------------------------------------------------------------------
   // Returns the top of the stack value but doesn't remove it.
   //---------------------------------------------------------------------
   StackInfoType peek();
   
   //---------------------------------------------------------------------
   // Gets size of count
   //---------------------------------------------------------------------
   int size();
private:
   StackInfoType elements[MAXSTACK];
   int top;
};

#endif	/* STACK_H */

