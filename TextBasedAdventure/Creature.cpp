#include "Creature.h"

void Creature::SetType(int type)
{
	this->type = type;
}

int Creature::GetRoom()
{
	return this->room;
}

void Creature::SetRoom(int room)
{
	this->room = room;
}