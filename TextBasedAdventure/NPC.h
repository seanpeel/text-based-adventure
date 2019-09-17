#include "Creature.h"

#pragma once
class Npc : public Creature
{
private:
	void grumble(int& respect, int state);
	void smile(int& respect, int state);
public:
	Npc();
	void React(int& respect, int state, int action);
};

