#include "Room.h"

#pragma once
class Creature
{
private:
	int type = -1;
	int room = -1;
	int name = -1; //simply the creatures index in the master creatures array
public:
	Creature(int type, int room);
	Creature();

	int GetType();
	void SetType(int type);

	int GetRoom();
	void SetRoom(int room);

	int GetName();
	void SetName(int name);

	int Move(int creature, int src, int dest, Room** rooms);
};

