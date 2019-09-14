#include "Room.h"

Room::Room()
{

}

Room::Room(int state, int neighbors[4])
{
	this->state = state;

	for (int i = 0; i < 4; i++)
	{
		this->neighbors[i] = neighbors[i];
	}
}

int Room::GetState()
{
	return this->state;
}

void Room::SetState(int state)
{
	this->state = state;
}

int* Room::GetNeighbors()
{
	return neighbors;
}

int Room::GetTotalCreatures()
{
	return totalCreatures;
}

int* Room::GetCreatures() 
{
	return creatures;
}

void Room::AddCreature(int creature) 
{
	creatures[totalCreatures++] = creature;
}

void Room::RemoveCreature(int creature)
{
	for (int i = 0; i < totalCreatures; i++)
	{
		if (creatures[i] == creature)
		{
			for (int j = i; j < totalCreatures; j++)
			{
				creatures[j] = creatures[j + 1];
			}
			creatures[totalCreatures] = -1;
			break;
		}
	}
}
