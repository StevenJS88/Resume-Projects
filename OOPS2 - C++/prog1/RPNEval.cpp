//---------------------------------------------------------------------
// Name:    Steven Storkson
// Project: Reverse Polish Notation Evaluator with Queue and Stack.
// Purpose: The implemented class in this file will process expressions,
//          process them based on operand and operant, return if the 
//          expression is valid, and return the value/answer of the 
//          expression.
//---------------------------------------------------------------------
#include "RPNEval.h"
#include "string"

void RPNEval::ProcessExpression() 
{
   valid = true;
   bool done = false;
   char ch;
   cin >> ch;
   while (valid && !done) 
   {
      if (ch >= '0' && ch <= '9') 
      {
         cin.putback(ch);
         ProcessOperand();
      } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/') 
      {
         valid = ProcessOperant(ch);
      } else if (ch == '#') 
      {
         cout << endl;
         done = true;
      } else 
      {
         cout << ch << endl;
         valid = false;
      }
      if (valid && !done)
         cin >> ch;
   }
   cin.ignore(256, '\n');
   if (stack.isEmpty()) 
   {
      valid = false;
   } else if (valid) 
   {
      OperandType potentialAnswer  = stack.pop();
      if (stack.isEmpty())
         answer = potentialAnswer;
      else 
         valid = false;
   }
}

void RPNEval::PrintIntermediateResults() 
{ 
   OperandType result;
   int count = queue.size();
   cout << "The Intermediate Results are: ";
   for (int i = 0; i < count; i++) 
   {
      result = queue.dequeue();
      cout << result << " ";
   }
   cout << endl;
   ClearValues();
}

void RPNEval::ProcessOperand() 
{
   OperandType operand;
   cin >> operand;
   stack.push(operand);
   cout << operand << " ";
}
      
bool RPNEval::ProcessOperant(char opt) 
{
   OperandType op2;
   OperandType op1;
   OperandType solution = 0;
   cout << opt << " ";
   if (stack.size() > 1)
   { 
      op2 = stack.pop();
      op1 = stack.pop();
   } else {
      cout << endl;
      return false;
   }
   if (opt == '+') 
      solution = (op1 + op2);
   else if (opt == '-') 
      solution = (op1 - op2);
   else if (opt == '*')
      solution = (op1 * op2);
   else if (opt == '/' && op2 != 0) 
      solution = (op1 / op2);
   else 
   {
      cout << endl;
      return false;
   }
   queue.enqueue(solution);
   stack.push(solution);
   return true;
}

void RPNEval::ClearValues() 
{
   Stack s;
   Queue q;
   stack = s;
   queue = q;
}
