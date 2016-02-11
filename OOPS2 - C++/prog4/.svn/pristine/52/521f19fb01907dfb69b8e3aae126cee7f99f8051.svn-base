//---------------------------------------------------------------------
// Name:    Steven Storkson and Adam Nielsen
// Project: Progam 4
//
// Purpose: Prog4 - Maze Class header file
//         Used to solve a .DAT maze file based on certain input
//         It recusively solves the maze and determines if it found
//         the exit or not and displays the solved maze to the user.
//---------------------------------------------------------------------
#pragma once 
#include <vcclr.h>   
#include <fstream>
#include <iomanip>

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class Maze
{
public:
   //---------------------------------------------------------------------
   // The Maze Constructor that takes a panel and an ifstream from an
   // input file and creates a maze from the file contents.
   //---------------------------------------------------------------------
   Maze( Panel ^drawingPanel, ifstream &ifs );
	
   //---------------------------------------------------------------------
   // Returns the value of the boolean variable valid
   //---------------------------------------------------------------------
   bool IsValid() const { return valid; }

   //---------------------------------------------------------------------
   // Returns the value of the boolean variable free
   //---------------------------------------------------------------------
   bool IsFree() const { return free; }

   //---------------------------------------------------------------------
   // Takes an x and y coordinate selected by the user and tries to solve
   // the puzzle from that location
   //---------------------------------------------------------------------
   void Solve ( int xPixel, int yPixel );

   //---------------------------------------------------------------------
   // Shows the original maze on the panel
   //---------------------------------------------------------------------
   void ShowOriginal() { Show(orig); Clear();}

   //---------------------------------------------------------------------
   // Shows the Solved maze on the panel
   //---------------------------------------------------------------------
   void ShowSolved() { Show(solved); }

   //---------------------------------------------------------------------
   // passes the value of original to the solved maze character array 
   // then sets the free boolean variable to false.
   //---------------------------------------------------------------------
   void Clear();
private:
      static const int CELLSIZE = 16;
      static const int MAXSIZE = 30;

      static const char OPEN = 'O' ;
      static const char DEADEND = '+' ;
      static const char EXIT = 'E' ;
      static const char START = 'S' ;
      static const char VISITED = 'X';

      int width, height;
      bool free;
      bool valid;

      gcroot<System::Windows::Forms::Panel^> mazePanel;

      char orig[MAXSIZE][MAXSIZE];
      char solved[MAXSIZE][MAXSIZE];

	  //---------------------------------------------------------------------
      // Takes a coordinate and checks if the coordinate is an open spot, 
	  // start square, deadend, or visited coordinate.  It then attempts to
	  // move through the maze to find the end.  
	  // Changes free to true if finds the Exit Character.
      //---------------------------------------------------------------------
      void RecSolve ( int row, int col );

	  //---------------------------------------------------------------------
      // Displays the character array passed to it.
      //---------------------------------------------------------------------
      void Show ( char cells[MAXSIZE][MAXSIZE] );
};