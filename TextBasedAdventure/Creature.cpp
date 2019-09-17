#include "Creature.h"

Creature::Creature()
{

}

Creature::Creature(int type, int room)
{
	this->type = type;
	this->room = room;
}

int Creature::GetType()
{
	return this->type;
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

int Creature::GetName()
{
	return this->name;
}

void Creature::SetName(int name)
{
	this->name = name;
}

int Creature::Move(int creature, int src, int dest, Room** rooms)
{
	if (dest != -1)
	{
		//Remove from source room;
		Room* srcRoom = rooms[src];
		srcRoom->RemoveCreature(creature);

		//Add to destination room;
		Room* destRoom = rooms[dest];
		destRoom->AddCreature(creature);

		//Update creature room information;
		SetRoom(dest);

		return 0;
	}
	else
	{
		return -1;
	}
}