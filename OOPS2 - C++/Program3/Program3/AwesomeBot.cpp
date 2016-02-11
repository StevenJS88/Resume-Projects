#include "AwesomeBot.h"

AwesomeBot::AwesomeBot(int X, int Y, Panel ^p) : VBot(X, Y , p)
{
	gcroot<Drawing::Bitmap ^> Image; 
	image = dynamic_cast<Drawing::Bitmap ^>(Image->FromFile("media_player_1_.bmp"));
	energy += 20;
}


AwesomeBot::~AwesomeBot(void)
{
	return;
}

int AwesomeBot::EnergyToFightWith()
{
	return energy;
}

void AwesomeBot::Move()
{
	if ( x + 40 < 0 )
		x = panel->Width;
	x -= 5;
}

void AwesomeBot::Show()
{
	Graphics ^ g = panel->CreateGraphics();
    g->DrawImage( image, x, y );
    g->~Graphics();
}
