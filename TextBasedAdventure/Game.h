#include "Creature.h"
#include "Player.h"
#include "Room.h"

#pragma once
class Game
{
private:
	Room* rooms[100];
	Creature* creatures[100];
	Player* player;

	// DIRECTIONS
	const int NORTH = 0;
	const int SOUTH = 1;
	const int EAST = 2;
	const int WEST = 3;

	// CREATURE TYPES
	const int PLAYER = 0;
	const int ANIMAL = 1;
	const int NPC = 2;
public:
	void SetUp();
	int Play();
};

