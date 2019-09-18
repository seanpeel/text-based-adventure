#include "Animal.h"
#include "Creature.h"
#include "NPC.h"
#include "Player.h"
#include "Room.h"

#pragma once
class Game
{
private:
	Room* rooms[100];
	Creature* creatures[100];
	Player* player;

	int playerIndex = -1;

	// DIRECTIONS
	const int NORTH = 0;
	const int SOUTH = 1;
	const int EAST = 2;
	const int WEST = 3;

	// CREATURE TYPES
	const int PLAYER = 0;
	const int ANIMAL = 1;
	const int NPC = 2;

	// ACTIONS
	const int CLEAN = 0;
	const int DIRTY = 1;

public:
	void SetUp();
	int Play();
};

