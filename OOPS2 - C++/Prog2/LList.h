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
   // Checks if the list is empty
   //---------------------------------------------------------------------
   bool IsEmpty() const;
   
   //---------------------------------------------------------------------
   // Inserts Object of Infotype into the Linked List if it's not in the 
   // list
   //---------------------------------------------------------------------
   bool Insert ( InfoType * x_ptr );
   
   //---------------------------------------------------------------------
   // Deletes Object of InfoType from LList
   //---------------------------------------------------------------------
   bool Delete ( const InfoType & x );
   
   //---------------------------------------------------------------------
   // Display Fruit Name and Code information from the nodes in the list
   //---------------------------------------------------------------------
   void Display ( ostream & out_stream );

private:
   //---------------------------------------------------------------------
   // Stack class data structure for storing numeric values
   //---------------------------------------------------------------------
   struct Node
   {
      //---------------------------------------------------------------------
   // Node constructor
   //---------------------------------------------------------------------
      Node ( InfoType * x, Node * p = NULL ) { infoPtr = x;  next = p; }
      //---------------------------------------------------------------------
   // Node destructor
   //---------------------------------------------------------------------
      ~Node() { delete infoPtr; }
      
      InfoType * infoPtr;
      Node * next;
   };

   Node * list;
   
   //---------------------------------------------------------------------
   // Linked List Copy Constructor: not used
   //---------------------------------------------------------------------
   LList ( const LList & copyFrom );                 // Don't allow!
   
   //---------------------------------------------------------------------
   // Linked List assignment operator overload: not used
   //---------------------------------------------------------------------
   LList & operator= ( const LList & assignFrom );   // Don't allow!
};


#endif	/* LLIST_H */

