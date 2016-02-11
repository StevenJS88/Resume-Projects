#pragma once
#include "VBot.h"
class HappyBot : public VBot
{
public:
	int state;
	HappyBot(int X, int Y, Panel ^p);
	~HappyBot(void);
	void Move();
	void Show();
	void Dead();
	int EnergyToFightWith();
};

