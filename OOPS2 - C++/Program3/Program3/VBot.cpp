// You must properly comment, and remove all my "commentary".


// All CPP files need this as the first line after comment block.
#include "stdafx.h"     
#include "VBot.h"

void VBot::Show()
{ 
   Graphics ^ g = panel->CreateGraphics();
   g->DrawImageUnscaled( image, x, y );
   g->~Graphics();
}

// Don't rewrite or override this one! 
bool VBot::CollidedWith ( VBot * b ) const
{
   if (  b == NULL )
      return false;

   return   ( x + image->Width ) >= b->x
         && ( b->x + b->image->Width ) >= x
         && ( y + image->Height ) >= b->y
         && ( b->y + b->image->Height ) >= y;

}

void VBot::Dead()
{
	gcroot<Drawing::Bitmap ^> Image; 
	image =  dynamic_cast<Drawing::Bitmap ^>(Image->FromFile("X.png"));
}

// Don't override this one, but you can modify 
// what's here it if you want.
// Make sure you have good reasons for any changes!
void VBot::DoBattleWith ( VBot * b )
{
   int mine = EnergyToFightWith();
   int yours = b->EnergyToFightWith();
   if( mine == yours )
   {
      energy = energy - mine / 2;
      b->energy = b->energy - yours / 2;
   }
   else if ( mine > yours )
   {
      if ( b->energy > 1 )
      {
         b->energy = b->energy - yours;
         energy = energy + yours / 2;
      }
      else
      {
         b->energy = b->energy - 1;
         energy = energy + 1;
      }
   }
   else
   {
      if ( energy > 1 )
      {
         energy = energy - mine;
         b->energy = b->energy + mine / 2;
      }
      else
      {
         b->energy = b->energy + 1;
         energy = energy - 1;
      }
   }
   //Moving both combatants away from battle
   x += 150;
   y += 30;
   b->x -= 150;
   b->y -= 30;

}
