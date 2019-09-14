#include "Creature.h"
#pragma once

class Animal : public Creature
{
private:
public:
	Animal();
	void growl(int& respect);
	void lickFace(int& respect);
};

