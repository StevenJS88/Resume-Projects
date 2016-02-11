//---------------------------------------------------------------------
// Name:    Steven Storkson
// Project: Reverse Polish Notation Evaluator with Queue and Stack.
// Purpose: This implementation has a constructor for the class stack,
//          can check if the stack is full or empty, can add or remove
//          elements of type StackInfoType.
//---------------------------------------------------------------------
#include "Stack.h"

Stack::Stack() 
{ 
   top = 0;
}

bool Stack::isEmpty() 
{
   return top == 0;
}

bool Stack::isFull() 
{
   return (top == MAXSTACK);
}

void Stack::push(StackInfoType num) 
{
      elements[top++] = num;
}

StackInfoType Stack::pop() 
{
      return elements[--top];
}

StackInfoType Stack::peek() 
{
   return elements[top - 1];
}

int Stack::size() 
{
   return top;
}


#ifdef TESTING_STACK

// ------------------------------
// Testbed main
// ------------------------------
int main()
{
   Stack s;
   s.push(12.1);
   cout << s.peek() << " This is the number I just pushed and peeked at." << endl;
   cout << s.pop() << endl;
   s.push(13.5);
   cout << s.peek() << " This is the number I just pushed and peeked at." << endl;
   s.push(5.9);
   cout << s.peek() << " This is the number I just pushed and peeked at." << endl;
   if (s.isEmpty()) 
      cout << "Stack is empty" << endl;
   else
      cout << "Stack is Not Empty." << endl;
   
   if (s.isFull()) 
      cout << "Stack is full" << endl;
   else
      cout << "Stack is Not full." << endl;
   cout << s.size() << " Is how many elements I have in my stack." << endl;
   cout << s.pop() << endl;
   cout << s.pop() << endl;
   
   // .... etc, to test all the methods.
   return 0;
}

#endif
