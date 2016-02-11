//---------------------------------------------------------------------
// Name:    Steven Storkson
// Project: 
//
// Purpose: Prog2
//
//---------------------------------------------------------------------

#include "Fruit.h"

Fruit::Fruit(const Fruit& orig) 
{
   char testChar;
   int count = 0;
   testChar = orig.name[count];
   while(testChar != '0')
   {
      testChar = orig.name[count];
	  count++;
   }
   name = new char [count];
   for(int i = 0; i <= count; i++)
      name[i] = orig.name[i];
   name[count] = '0';
   count = 0;
   testChar = orig.code[count];
   while (count < CODE_LEN)
   {
      code[count] = orig.code[count];
      count++;
      testChar = orig.code[count];
   }
}

Fruit & Fruit::operator=(const Fruit & rhs)
{
   // follow steps in class
   if (this != &rhs)
   {
        // De-allocating Dynamic Memory with destructor
	   *name = *rhs.name; //using Copy Constructor for Alloc and Copy, check!!!
	   *code = *rhs.code;

   }
      return *this;
}

bool Fruit::operator<(const Fruit & rhs) const 
{
   return (name[0] < rhs.name[0]);
}

bool Fruit::operator==(const Fruit &rhs) const 
{
   if (this != &rhs)
   {
      bool equal = true;
      for (int i = 0; name[i] != '0' && equal; i++ )
      {
		  equal = (name[i] == rhs.name[i]);
      }
      return equal;
   }
   return true;
}

bool Fruit::operator!=(const Fruit &rhs) const
{
   return !(this->operator==(rhs));
}

istream & operator>>(istream &in, Fruit & rhs)
{
   bool done = false;
   char NameVal[MAX_NAME_LEN];
   char CodeVal;
   int count = 0;
   for(int i = 0; i < MAX_NAME_LEN && !done; i++)
   {
      in >> NameVal[i];
      if ( NameVal[i] > '0' && NameVal[i] < '9')
      {
         cin.putback(NameVal[i]);
         NameVal[i] = '0';
         done = true;
		 count++;
      }
      else
	  {
         count++;
	  }
   }
   if (rhs.name == NULL)
      rhs.name = new char[count];
   else
   {
      rhs.~Fruit();
      rhs.name = new char[count];
   }
   for (int i = 0; i < count; i++)
      rhs.name[i] = NameVal[i];
   for(int i = 0; i < CODE_LEN; i++ )
   {
      in >> CodeVal;
      if(CodeVal != '\n')
         rhs.code[i] = CodeVal;
   }
   return in;
}

ostream & operator<<(ostream &os, Fruit &rhs)
{
   
	
   for (int i = 0; i < MAX_NAME_LEN && rhs.name[i] != '0'; i++)
      os << rhs.name[i];
   os << " ";
   for (int i = 0; i < CODE_LEN; i++)
      os << rhs.code[i];
	  
   return os;
}


#ifdef TESTING_FRUIT

// ------------------------------
// Testbed main
// ------------------------------
void main()
{
   Fruit num1 = Fruit();
   Fruit num2 = Fruit();
   cin >> num1;
   cin >> num2;
   Fruit num3 = Fruit(num1);
   bool value = num3 == num1;
   if(value)
	   cout << "true" << endl;
   else
      cout << "false" << endl;

   cout << "Hello" << endl;
   cout << num3 << endl;
   cout << num2 << endl;
   num1.~Fruit();
   num2.~Fruit();
   num3.~Fruit();
}

#endif