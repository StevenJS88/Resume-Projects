//---------------------------------------------------------------------
// Name:    Steven Storkson
// Project: 
//
// Purpose: Prog2
//
//---------------------------------------------------------------------
#include "LList.h"

LList::~LList()
{
   Node * p = list;
   while(p != NULL)
   {
	   list = list->next;
	   delete p;
	   p = list;
   }
}

bool LList::IsEmpty() const
{
   return (list == NULL);
}

bool LList::Insert ( InfoType * x_ptr )
{
    bool notInTheList = true;
	Node * p = list;
	if(p != NULL)
	{
		if(p->infoPtr != x_ptr)
		{
			while(p->next != NULL && p->next->infoPtr < x_ptr)
			{
				p = p->next;
			}
			if(p->infoPtr != x_ptr)
			{
				p->next = new Node(x_ptr, p->next);
				return true;
			}
			else
			{
			   delete x_ptr;
			   return false;
			}
		}
		else
		{
		    delete x_ptr;
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
	if(q != NULL)
	{
		if(*q->infoPtr != x )
		{
			while (q != NULL && *q->infoPtr != x )
			{
				p = q;
				q = q->next;
			}
			if(q != NULL)
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
	   out_stream << endl ;
	   out_stream << endl;
   }
   else
   {
	   out_stream << endl;
	   out_stream << endl;
   }
}

#ifdef TESTING_LLIST

// ------------------------------
// Testbed main
// ------------------------------
int main()
{
   
   return 0;
}

#endif