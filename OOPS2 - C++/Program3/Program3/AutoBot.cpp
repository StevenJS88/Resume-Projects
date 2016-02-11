#include "AutoBot.h"

AutoBot::AutoBot(int X, int Y, Panel ^p) : VBot(X, Y , p)
{
	gcroot<Drawing::Bitmap ^> Image; 
	image = dynamic_cast<Drawing::Bitmap ^>(Image->FromFile("autobot.png"));
	energy += 30;
}


AutoBot::~AutoBot(void)
{
	return;
}

int AutoBot::EnergyToFightWith()
{
	return energy;
}

void AutoBot::Move()
{
	if ( x < 0 )
		x = panel->Width;
	if ( y < 0 )
		y = panel->Height;
	x -= 15;
	y -= 5;
}

void AutoBot::Show()
{
	Graphics ^ g = panel->CreateGraphics();
    g->DrawImage( image, x, y );
    g->~Graphics();
}
