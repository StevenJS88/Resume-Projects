//---------------------------------------------------------------------
// Name:    Steven Storkson
// Project: 
//
// Purpose: Prog2
//
//---------------------------------------------------------------------

#ifndef FRUIT_H
#define	FRUIT_H

//#define TESTING_FRUIT
#ifdef TESTING_FRUIT
   #include <iostream>
   using namespace std;
#endif



enum { CODE_LEN = 4 };
enum { MAX_NAME_LEN = 30 };

//---------------------------------------------------------------------
//  Fruit Object Class... etc...
//---------------------------------------------------------------------
class Fruit {
public:
   
   //---------------------------------------------------------------------
   // Default Constructor
   //---------------------------------------------------------------------
   Fruit() {name = NULL;};
   
   //---------------------------------------------------------------------
   // Copy Constructor
   //---------------------------------------------------------------------
   Fruit(const Fruit &orig);
   
   //---------------------------------------------------------------------
   // Destructor
   //---------------------------------------------------------------------
   ~Fruit() { delete [] name; name = NULL;};
    
   //---------------------------------------------------------------------
   // Assignment Operator Overload Function
   //---------------------------------------------------------------------
   Fruit & operator=(const Fruit & rhs);
   
   //---------------------------------------------------------------------
   // Less Than Operator Overload Function
   //---------------------------------------------------------------------
   bool operator<(const Fruit &rhs) const;
   
   //---------------------------------------------------------------------
   // Equals Operator Overload Function
   //---------------------------------------------------------------------
   bool operator==(const Fruit &rhs) const;
   
   //---------------------------------------------------------------------
   // Not Equals Operator Overload Function
   //---------------------------------------------------------------------
   bool operator!=(const Fruit &rhs) const;
   
   //---------------------------------------------------------------------
   // In Operator Overload Function
   //---------------------------------------------------------------------
   friend istream & operator>>(istream & in, Fruit & rhs);
   
   //---------------------------------------------------------------------
   // Out Operator Overload Function
   //---------------------------------------------------------------------
   friend ostream & operator<<(ostream & os, Fruit & rhs);
   
private:
   char * name;             // allocate memory (use new) - zero-terminated
   char code[CODE_LEN];     // NOT zero-terminated (be careful!)
};
#endif	/* FRUIT_H */

