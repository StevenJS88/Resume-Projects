// You must properly comment, and remove all my "commentary".
// Remember, comment blocks go on the method in here (the H file).

#pragma once      // This is instead of the "#ifndef guard"

// Needed for gcroot declaration:  allow use of GC class in non-GC class
#include <vcclr.h>   

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class VBot
{
public:

   VBot( int startX, int startY, Panel ^ drawingPanel ) : 
      x(startX), y(startY), panel(drawingPanel), energy(100), image(NULL) { }

   // Since this uses GC class pointers, you don't delete anything.
   // However, you could make destructors in the derived classes
   // to specify how this thing dies.  For example, show a
   // different icon and/or play a sound.
   virtual ~VBot() { }

   // You write this is the derived classes.
   // Move function for VBot - Must handle walls properly.
   // Must use x and y.  Must use properties of image and panel.
   virtual void Move() = 0;

   // You write this is the derived classes.
   // It must return a number between 1 and energy.
   // This number can vary.
   virtual int EnergyToFightWith() = 0;

   bool IsDead() const { return energy <= 0; }

   virtual void Show();

   bool CollidedWith ( VBot * b ) const;

   void DoBattleWith ( VBot * b );
   
protected:
      int x, y;                           // Current position of the VBot
      gcroot<Drawing::Bitmap ^> image;    // Image displayed for the VBot
      gcroot<Panel ^> panel;              // Panel on which to show the VBot.
      int energy;                         // Current energy of the VBot
};