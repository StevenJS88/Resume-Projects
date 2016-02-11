//---------------------------------------------------------------------
// Name:    Steven Storkson
// Project: 
//
// Purpose: Prog2
//
//---------------------------------------------------------------------
#ifndef LLIST_H
#define	LLIST_H


#include "Fruit.h"
typedef Fruit InfoType;

#define TESTING_LLIST
#ifdef TESTING_LLIST
   #include <iostream>
   using namespace std;
#endif

//---------------------------------------------------------------------
// LLIST class data structure for storing nodes
//---------------------------------------------------------------------
class LList
{

public:
   //---------------------------------------------------------------------
   // Default Constructor
   //---------------------------------------------------------------------
   LList() { list = NULL; }
   
   //---------------------------------------------------------------------
   // Destructor
   //---------------------------------------------------------------------
   ~LList();    // delete all the nodes
   
   //---------------------------------------------------------------------
   // Stack class data structure for storing numeric values
   //---------------------------------------------------------------------
   bool IsEmpty() const;
   
   //---------------------------------------------------------------------
   // Stack class data structure for storing numeric values
   //---------------------------------------------------------------------
   bool Insert ( InfoType * x_ptr );
   
   //---------------------------------------------------------------------
   // Deletes Object of InfoType from LList
   //---------------------------------------------------------------------
   bool Delete ( const InfoType & x );
   
   //---------------------------------------------------------------------
   // Stack class data structure for storing numeric values
   //---------------------------------------------------------------------
   void Display ( ostream & out_stream );

private:
   //---------------------------------------------------------------------
   // Stack class data structure for storing numeric values
   //---------------------------------------------------------------------
   struct Node
   {
      //---------------------------------------------------------------------
   // Stack class data structure for storing numeric values
   //---------------------------------------------------------------------
      Node ( InfoType * x, Node * p = NULL ) { infoPtr = x;  next = p; }
      //---------------------------------------------------------------------
   // Stack class data structure for storing numeric values
   //---------------------------------------------------------------------
      ~Node() { delete infoPtr; }
      
      InfoType * infoPtr;
      Node * next;
   };

   Node * list;
   
   //---------------------------------------------------------------------
   // Stack class data structure for storing numeric values
   //---------------------------------------------------------------------
   LList ( const LList & copyFrom );                 // Don't allow!
   
   //---------------------------------------------------------------------
   // Stack class data structure for storing numeric values
   //---------------------------------------------------------------------
   LList & operator= ( const LList & assignFrom );   // Don't allow!
};


#endif	/* LLIST_H */

