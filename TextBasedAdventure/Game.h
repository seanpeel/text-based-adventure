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
public:
	void SetUp();
	int Play();
};

