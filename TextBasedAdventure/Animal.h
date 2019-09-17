#include "Creature.h"
#pragma once

class Animal : public Creature
{
private:
	void Growl(int& respect, int state);
	void LickFace(int& respect, int state);
	void StrongGrowl(int& respect, int state);
	void StrongLickFace(int& respect, int state);
public:
	Animal();
	void React(int& respect, int state, int action);
	void StrongReact(int& respect, int state, int action);
};

