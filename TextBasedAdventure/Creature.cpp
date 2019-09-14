#include "Creature.h"

Creature::Creature()
{

}

Creature::Creature(int type, int room)
{
	this->type = type;
	this->room = room;
}

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