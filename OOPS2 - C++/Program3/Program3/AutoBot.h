#pragma once
#include "VBot.h"
class AutoBot : public VBot
{
public:
	AutoBot(int X, int Y, Panel ^p);
	~AutoBot(void);
	void Move();
	void Show();
	int EnergyToFightWith();
};

