#include "HappyBot.h"

HappyBot::HappyBot(int X, int Y, Panel ^p) : VBot(X, Y , p)
{
	state = 1;
	gcroot<Drawing::Bitmap ^> Image; 
	image = dynamic_cast<Drawing::Bitmap ^>(Image->FromFile("Run (1).png"));
	energy -= 20;
}


HappyBot::~HappyBot(void)
{
	return;
}

int HappyBot::EnergyToFightWith()
{
	return energy;
}

void HappyBot::Move()
{
	if ( x + 40 > panel->Width )
		x = 0;
	if ( y + 40 > panel->Height )
		y = 0;
	gcroot<Drawing::Bitmap ^> Image;
	if ( state == 3 )
	{
		x += 5;
	    y += 5;
	}
	else if (state == 1)
	{
		image = dynamic_cast<Drawing::Bitmap ^>(Image->FromFile("Run (2).png"));
		state = 2;
		x += 5;
	    y += 5;
	}
	else
	{
		image = dynamic_cast<Drawing::Bitmap ^>(Image->FromFile("Run (1).png"));
		state = 1;
		x += 5;
	    y += 5;
	}
}

void HappyBot::Dead()
{
	gcroot<Drawing::Bitmap ^> Image;
	image = dynamic_cast<Drawing::Bitmap ^>(Image->FromFile("Dead (10).png"));
	state = 3;
}

void HappyBot::Show()
{
	Graphics ^ g = panel->CreateGraphics();
    g->DrawImage( image, x, y );
    g->~Graphics();
}
