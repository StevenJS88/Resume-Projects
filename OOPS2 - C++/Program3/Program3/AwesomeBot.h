#pragma once
#include "VBot.h"
class AwesomeBot : public VBot
{
public:
	AwesomeBot(int X, int Y, Panel ^p);
	~AwesomeBot(void);
	void Move();
	void Show();
	int EnergyToFightWith();
};

