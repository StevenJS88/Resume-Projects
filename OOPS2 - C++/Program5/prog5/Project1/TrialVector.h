//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
#pragma once
#include "PrecisionTimer.h"
#include "Trial.h"
#include <vector>
#include <string>
using namespace std;
typedef vector<string> StringList;

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
class TrialVector : public Trial
{
public:

   //------------------------------------------------------------------------
   //
   //------------------------------------------------------------------------
	TrialVector ( StringList & s, int num_runs, TrialType t ): Trial(s, num_runs, t	) {};

   //------------------------------------------------------------------------
   // returns number of microseconds it took to add and remove the items.
   //------------------------------------------------------------------------
   unsigned int Run();

   //------------------------------------------------------------------------
   //  The Destructor of the TrialVector class calls the protected Clear() 
   //  method to delete the items in the vector.
   //------------------------------------------------------------------------
   virtual ~TrialVector() { Clear(); }

protected:
   StringList tVector;

   //------------------------------------------------------------------------
   // clears the container class
   //------------------------------------------------------------------------
   virtual void Clear();
   
   //------------------------------------------------------------------------
   // Adds an element to the vector class at index i in the vector.
   //------------------------------------------------------------------------
   virtual void AddElement( int i );
   
   //------------------------------------------------------------------------
   // I have no idea what to do with this.
   //------------------------------------------------------------------------
   struct WrongRemoveCalled { };

   //------------------------------------------------------------------------
   // Removes an element in the vector in the specified type order
   //------------------------------------------------------------------------
   virtual void RemoveElement();

private:
   PrecisionTimer timer;
   int numRuns;

};