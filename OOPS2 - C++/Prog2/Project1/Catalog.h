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

//---------------------------------------------------------------------
// Stack class data structure for storing numeric values
//---------------------------------------------------------------------
class Catalog {
public:
   //---------------------------------------------------------------------
   // Default Constructor
   //---------------------------------------------------------------------
   Catalog();
   
   Catalog(const Catalog& orig);
   
   //---------------------------------------------------------------------
   // Destructor
   //---------------------------------------------------------------------
    ~Catalog();
   
   //---------------------------------------------------------------------
   // 
   //---------------------------------------------------------------------
   //void Run();
   
private:
   
   LList List;
   
   bool Insert();
   bool Delete();
   void Print();
   
};

#endif	/* CATALOG_H */
