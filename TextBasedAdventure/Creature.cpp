#include "Creature.h"
#include <stdio.h>

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
		Room* srcRoom = rooms[src];
		Room* destRoom = rooms[dest];

		int totalCreatures = destRoom->GetTotalCreatures();
		
		if (totalCreatures < 9)
		{
			//Remove from source room;
			srcRoom->RemoveCreature(creature);

			//Add to destination room;
			destRoom->AddCreature(creature);

			//Update creature room information;
			SetRoom(dest);

			return 0;
		} 
		else
		{
			printf("%s %d %s","Room", dest, "is full.");
		}
	}
	else
	{
		return -1;
	}
}