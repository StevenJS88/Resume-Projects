//---------------------------------------------------------------------
// Name:    Steven Storkson
// Project: Reverse Polish Notation Evaluator with Queue and Stack.
// Purpose: This file will show all the method names and types to be
//          implemented in the implementation .cpp file.
//---------------------------------------------------------------------
#ifndef __RPNEVAL_H
#define __RPNEVAL_H

#include "stack.h"
#include "queue.h"

#include <iostream>

using namespace std;

typedef float OperandType;

// ----------------------------------------------------------------
// Processes the user input expressions
// ----------------------------------------------------------------
class RPNEval
{
   public:

      //---------------------------------------------------------------------
      // RPNEval constructor
      //---------------------------------------------------------------------
      RPNEval() { valid = false; }

      //---------------------------------------------------------------------
      // Reads and processes the next RPN expression from the standard input.
      //---------------------------------------------------------------------
      void ProcessExpression();

      //---------------------------------------------------------------------
      // Returns true if RPN expression is valid, false otherwise.
      //---------------------------------------------------------------------
      bool IsValid() const { return valid; }

      //---------------------------------------------------------------------
      // Returns the value of the RPN expression if it is valid.
      // Returns garbage if RPN expression is not valid.
      //---------------------------------------------------------------------
      OperandType Value() const { return answer; }

      //---------------------------------------------------------------------
      // Print out the intermediate results to the standard
      // output, with one space after each result.
      // Does NOT print any header or any newlines.
      //---------------------------------------------------------------------
      void PrintIntermediateResults();

   private:
      bool valid;                   // Is RPN expression valid?
      OperandType answer;           // Value of RPN expression if it is valid
      Stack stack;                  // Used to process RPN
      Queue queue;                  // Used to store intermediate results


      // You can't add any more private data but you MUST have
      // some private methods!
      
      
      //---------------------------------------------------------------------
      // processes the numeric values
      //---------------------------------------------------------------------
      void ProcessOperand();
      
      //---------------------------------------------------------------------
      // Processes the equation
      //---------------------------------------------------------------------
      bool ProcessOperant(char ch);
      
      //---------------------------------------------------------------------
      // Resets the values of Stack and Queue so it doesn't keep garbage vals
      //---------------------------------------------------------------------
      void ClearValues();
};
#endif

