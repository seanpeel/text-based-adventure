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

void Room::SetNeighbors(int* neighbors)
{
	this->neighbors = neighbors;
}