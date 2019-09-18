#include "Room.h"
#include <stdio.h>

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

int& Room::GetTotalCreatures()
{
	return totalCreatures;
}

int* Room::GetCreatures() 
{
	return creatures;
}

void Room::AddCreature(int creature)
{
	this->creatures[totalCreatures++] = creature;
}

int Room::RemoveCreature(int creature)
{
	for (int i = 0; i < totalCreatures; i++)
	{
		if (creatures[i] == creature)
		{
			for (int j = i; j < totalCreatures; j++)
			{
				
				if (j + 1 < 10)
				{
					creatures[j] = creatures[j + 1];
				}
				
			}
			creatures[totalCreatures - 1] = -1;
			totalCreatures--;
			return 0;
		}
	}
	
	return -1;
}

void Room::Clean()
{
	if (state != 0)
	{
		state--;
	}
	else
	{
		printf("%s\n", "This room is already clean.");
	}
}

void Room::Dirty()
{
	if (state != 2) 
	{
		state++;
	}
	else
	{
		printf("%s\n", "This room is already dirty.");
	}
}