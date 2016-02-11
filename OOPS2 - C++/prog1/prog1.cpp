//---------------------------------------------------------------------
// Name:    Steven Storkson
// Project: Reverse Polish Notation Evaluator with Queue and Stack.
//
// Purpose: This code include the iostream and cstdlib for console
//          display of information.  The "RPNEval.h" file is the class
//          that will evaluate the expressions that the user inputs.
//          It takes in the number of expressions, initializes a RPNEval
//          object for processing the expressions and then reads and 
//          displays the evaluation of the expression back to the user.
//
//---------------------------------------------------------------------

#include <cstdlib>
#include <iostream>

#include "RPNEval.h"

using namespace std;


int main(int argc, char** argv)
{
   int num_expressions;
   cin >> num_expressions;
   RPNEval rpn;
   for(int i = 1; i <= num_expressions; i++)
   {
      cout << "Expression " << i << ":" << endl;
      rpn.ProcessExpression();
      if (rpn.IsValid()) 
         cout << "The value is: " << rpn.Value() << endl;
      else 
         cout << "Invalid Expression" << endl;
      rpn.PrintIntermediateResults();
      cout << endl;
   }
   cout << "Normal Termination of Program 1!" << endl;;
   return 0;
} 
