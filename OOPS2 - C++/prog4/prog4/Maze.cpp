#include "Maze.h"
Maze::Maze( Panel ^drawingPanel, ifstream &ifs )
{
   mazePanel = drawingPanel;
   ifs >> width;
   ifs >> height;
   for (int i = 0; i < height; i++)
      for (int j = 0; j < width; j++)
      {
         ifs >> orig[j][i];
         solved[j][i] = orig[j][i];
         if (orig[j][i] != OPEN && orig[j][i] != DEADEND 
            && orig[j][i] != EXIT )
            valid = false;
      }
      if (width > MAXSIZE || width <= 0 || height > MAXSIZE || height <= 0)
         valid = false;
      if (valid)
      {
         mazePanel->Width = width*CELLSIZE;
         mazePanel->Height = height*CELLSIZE;
      }
      free = false;
}

void Maze::Solve ( int xPixel, int yPixel )
{
   if (solved[yPixel][xPixel] == DEADEND)
   {
      return;
   }
   else
   {
      if( *orig[yPixel, xPixel] == EXIT)
      {
         free = true;
         return;
      }
      solved[yPixel][xPixel] = START;
      RecSolve(yPixel, xPixel);
      if (free)
      {
         //change text to free
         ShowSolved();
      }
      else
      {
         //change text to not free
         ShowSolved();
      }
   }
}


void Maze::RecSolve ( int row, int col )
{
   if (!free)
   {
      if( row >= 0 && row <= ( width - 1 ) && col >= 0 && col <= ( height - 1 ) )
      {
         if(solved[row][col] == EXIT)
         {
            free = true;
            return;
         }
         else if (solved[row][col] == DEADEND || solved[row][col] == VISITED)
            return;
         else
         {
            if(solved[row][col] != START)
               solved[row][col] = VISITED;
            RecSolve( row - 1, col ); //North
            RecSolve( row, col + 1 ); //East
            RecSolve( row + 1, col ); //South
            RecSolve( row, col - 1 ); //West
         }
      }
   }
}

void Maze::Show ( char cells[MAXSIZE][MAXSIZE] )
{
   Graphics ^ g = mazePanel->CreateGraphics();
   if (valid)
   {
      for (int i = 0; i < width; i++)
         for (int j = 0; j < height; j++)
         {
            if (cells[i][j] == OPEN)
               g->FillRectangle( gcnew SolidBrush (Color::White),
               i*CELLSIZE, j*CELLSIZE,
               mazePanel->Width/width, 
               mazePanel->Height/height );
            else if (cells[i][j] == DEADEND)
               g->FillRectangle( gcnew SolidBrush (Color::Black),
               i*CELLSIZE, j*CELLSIZE, 
               mazePanel->Width/width, 
               mazePanel->Height/height );
            else if (cells[i][j] == EXIT)
               g->FillRectangle( gcnew SolidBrush (Color::Red), 
               i*CELLSIZE, j*CELLSIZE, 
               mazePanel->Width/width, 
               mazePanel->Height/height );
            else if (cells[i][j] == START)
               g->FillRectangle( gcnew SolidBrush (Color::Green), 
               i*CELLSIZE, j*CELLSIZE, 
               mazePanel->Width/width, 
               mazePanel->Height/height );
            else if (cells[i][j] == VISITED)
               g->FillRectangle( gcnew SolidBrush (Color::Blue), 
               i*CELLSIZE, j*CELLSIZE, 
               mazePanel->Width/width, 
               mazePanel->Height/height );
         }
   }
   g->~Graphics();
}

void Maze::Clear()
{
   for (int i = 0; i < height; i++)
      for (int j = 0; j < width; j++)
      {
         solved[j][i] = orig[j][i];
      }
      free = false;
}