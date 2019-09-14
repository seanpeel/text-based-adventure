#include "Room.h"

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

void Room::SetNeighbors(int neighbors[4])
{
	for (int i = 0; i < 4; i++)
	{
		this->neighbors[i] = neighbors[i];
	}
}