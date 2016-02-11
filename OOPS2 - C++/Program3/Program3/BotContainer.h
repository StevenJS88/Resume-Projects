#pragma once
#include "VBot.h"
#include <cstdlib>
#include <vector>

using namespace std;
const int MAXSTARTGROWSIZE = 10;

typedef VBot T;
class BotContainer 
{
private:
	vector<T*> *botArray;
	vector<T*>::iterator *iter;

public:

	BotContainer() { botArray = new vector<T*>; *iter; }
	~BotContainer();
	void Insert(T *x);
	void Remove();
};