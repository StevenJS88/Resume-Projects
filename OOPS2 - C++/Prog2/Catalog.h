//---------------------------------------------------------------------
// Name:    Steven Storkson
// Project: 
//
// Purpose: Prog2
//
//---------------------------------------------------------------------

#ifndef CATALOG_H
#define	CATALOG_H
//#define CATALOG_TEST

#include "LList.h"
#include "Fruit.h"
#include <iostream>
typedef Fruit Type;

//---------------------------------------------------------------------
// Stack class data structure for storing numeric values
//---------------------------------------------------------------------
class Catalog {
public:
   //---------------------------------------------------------------------
   // Default Constructor
   //---------------------------------------------------------------------
   Catalog() { List = new LList(); }
   
   Catalog(const Catalog& orig);
   
   //---------------------------------------------------------------------
   // Destructor
   //---------------------------------------------------------------------
    ~Catalog();
   
   //---------------------------------------------------------------------
   // Starts input for catalog
   //---------------------------------------------------------------------
   void Run();
   
private:
   
   LList *List;
   
   bool Insert();
   bool Delete();
   void Print() { List->Display(cout); }
   
};

#endif	/* CATALOG_H */

