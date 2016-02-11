#include "MegaTronBot.h"

MegaTronBot::MegaTronBot(int X, int Y, Panel ^p) : VBot(X, Y , p)
{
	gcroot<Drawing::Bitmap ^> Image; 
	image = dynamic_cast<Drawing::Bitmap ^>(Image->FromFile("beast.bmp"));
	energy -= 30;
}


MegaTronBot::~MegaTronBot(void)
{
	return;
}

int MegaTronBot::EnergyToFightWith()
{
	return energy;
}

void MegaTronBot::Move()
{
	if ( x < 0 )
		x = panel->Width;
	if ( y < 0 )
		y = panel->Height;

	x -= 10;
	y -= 10;
}

void MegaTronBot::Show()
{
	Graphics ^ g = panel->CreateGraphics();
    g->DrawImage( image, x, y );
    g->~Graphics();
}
