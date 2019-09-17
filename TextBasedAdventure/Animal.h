#include "Creature.h"
#pragma once

class Animal : public Creature
{
private:
	void growl(int& respect, int state);
	void lickFace(int& respect, int state);
public:
	Animal();
	void React(int& respect, int state, int action);
};

