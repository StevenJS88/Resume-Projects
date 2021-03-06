// You comment this!!!

//#include "stdafx.h"

#include "PrecisionTimer.h"
#include <windows.h>

PrecisionTimer::PrecisionTimer()
{
   LARGE_INTEGER cps;
   LARGE_INTEGER init_cnt;

   QueryPerformanceCounter( &init_cnt );
   QueryPerformanceFrequency( &cps );

   start_count = init_cnt.QuadPart;
   microseconds_per_count = 1000000.0 / cps.QuadPart;
}

void PrecisionTimer::ReStart()
{
   LARGE_INTEGER init_cnt;
   QueryPerformanceCounter( &init_cnt );
   start_count = init_cnt.QuadPart;
}


// in microseconds
unsigned int PrecisionTimer::ElaspedTime() const
{
   LARGE_INTEGER cnt;
   QueryPerformanceCounter(&cnt);
   return (unsigned int)( ( cnt.QuadPart - start_count ) 
                         * microseconds_per_count + 0.5 );
}



