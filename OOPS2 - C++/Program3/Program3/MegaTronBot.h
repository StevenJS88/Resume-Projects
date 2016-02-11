#pragma once
#include "VBot.h"
class MegaTronBot : public VBot
{
public:
	MegaTronBot(int X, int Y, Panel ^p);
	~MegaTronBot(void);
	void Move();
	void Show();
	int EnergyToFightWith();
};

