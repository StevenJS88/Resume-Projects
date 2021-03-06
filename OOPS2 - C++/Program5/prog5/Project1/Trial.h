// Comment correctly, remove my commentary.

#pragma once

#include "PrecisionTimer.h"
#include <vector>
#include <string>
using namespace std;

typedef vector<string> StringList;

class Trial
{
public:

   enum TrialType { FRONT_FRONT, FRONT_REAR, REAR_FRONT, REAR_REAR, SORTED };

   Trial ( StringList & s, int num_runs, TrialType t )
      : strings(s), numRuns(num_runs), type(t) { }

   unsigned int Run();   // returns number of microseconds

   virtual ~Trial() {}   // Make sure destructor for derived class called!

protected:

   StringList & strings;    // reference variable!
   TrialType type;

   // Clear the container
   virtual void Clear() = 0;

   // The i refers to the ith element of strings.

   virtual void AddElement( int i ) = 0;

   struct WrongRemoveCalled { };

   // Only override one of these in each derived class!

   virtual void RemoveElement() { throw WrongRemoveCalled(); }

   virtual void RemoveElement( int i ) { throw WrongRemoveCalled(); }

private:
   PrecisionTimer timer;
   int numRuns;

};