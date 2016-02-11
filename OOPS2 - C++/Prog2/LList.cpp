//---------------------------------------------------------------------
// Name:    Steven Storkson
// Project: 
//
// Purpose: Prog2
//
//---------------------------------------------------------------------
#include "LList.h"
#include <iostream>

LList::~LList()
{
   Node *p = list;
   while(p != NULL)
   {
	   list = list->next;
	   delete &p;
	   p = list;
   }
}

bool LList::IsEmpty() const
{
   return (list == NULL);
}

bool LList::Insert ( InfoType * x_ptr )
{
	Node *p = list;
	if (p != NULL)
	{
		if ( *p->infoPtr != *x_ptr )
		{
			if ( !( *p->infoPtr < *x_ptr ) && *p->infoPtr != *x_ptr)
			{
				list = new Node( x_ptr, list);
				return true;
			}
			else
			{
			   while(p->next != NULL && *p->next->infoPtr < *x_ptr)
			   {
				  if( *p->infoPtr == *x_ptr )
				  {
					  return false;
				  }
				  p = p->next;
			   }
			   if( p->next != NULL && *p->next->infoPtr == *x_ptr )
			   {
				   return false;
			   }
			   p->next = new Node( x_ptr, p->next );
			   return true;
			}
		}
		else
		{
			return false;

		}
	}
	else
		list = new Node(x_ptr, list);
	return true;
}

bool LList::Delete ( const InfoType & x )
{
	Node *q = list;
	Node *p = NULL;
	if( q != NULL )
	{
		if( *q->infoPtr != x )
		{
			while ( q != NULL && *q->infoPtr != x )
			{
				p = q;
				q = q->next;
			}
			if( q != NULL )
			{
				p->next = q->next;
				delete q;
				return true;
			}
			else
				return false;
		}
		else
		{
			list = q->next;
			delete q;
			return true;
		}
	}
	else
		return false;
}

void LList::Display ( ostream & out_stream )
{
   Node *p = list;
   if(p != NULL)
   {
	   out_stream << "Below are the fruits currently in the list" << endl;
	   while(p != NULL)
	   {
		   out_stream << *p->infoPtr << endl;
		   p = p->next;
	   }
	   out_stream << endl;
   }
   else
   {
	   out_stream << "Below are the fruits currently in the list" << endl;
	   out_stream << endl;
   }
}
/*
#ifdef TESTING_LLIST

// ------------------------------
// Testbed main
// ------------------------------
int main()
{
   LList *newList = new LList();

   InfoType *new1 = new Fruit();
   InfoType *new2 = new Fruit();
   InfoType *new3 = new Fruit();
   InfoType *new4 = new Fruit();

   cin >> *new1;
   cin >> *new2;
   cin >> *new3;
   cin >> *new4;

   if( newList->Insert(new1) )
	   cout << "Added to the list: " << *new1 << endl;
   else
		cout << "Already in the list. " << endl;

   if( newList->Insert(new2) )
	   cout << "Added to the list: " << *new2 << endl;
   else
		cout << "Already in the list. " << endl;

   if (newList->Insert(new3))
	   cout << "Added to the list: " << *new3 << endl;
   else
		cout << "Already in the list. " << endl;

   if (newList->Insert(new4))
	   cout << "Added to the list: " << *new4 << endl;
   else
		cout << "Already in the list. " << endl;

   if(newList->IsEmpty())
      cout << "Empty List" << endl;
   else
	   cout << "List Not Empty" << endl;

   newList->Display(cout);

   InfoType *new5 = new Fruit();

   cin >> *new5;

   if ( newList->Delete( *new5 ) )
	   cout << "deleted" << endl;
   else
	   cout << "NOT deleted..." << endl;
   newList->Display(cout);


    InfoType *new6 = new Fruit();

   cin >> *new5;

   if ( newList->Insert( new6 ) )
	   cout << "deleted" << endl;
   else
	   cout << "NOT deleted..." << endl;


   newList->Display(cout);
   newList->~LList();
   if(newList->IsEmpty())
      cout << "Empty List" << endl;
   else
	   cout << "List Not Empty" << endl;
   return 0;
}
#endif
*/