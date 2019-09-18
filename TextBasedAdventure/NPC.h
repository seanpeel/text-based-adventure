#include "Creature.h"

#pragma once
class Npc : public Creature
{
private:
	void Grumble(int& respect);
	void Smile(int& respect);
	void StrongGrumble(int& respect);
	void StrongSmile(int& respect);
public:
	Npc();
	void React(int& respect, int state, int action);
	void StrongReact(int& respect, int state, int action);
};

