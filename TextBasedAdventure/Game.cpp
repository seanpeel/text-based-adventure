#include "Game.h"
#include "Util.h"


#include <iostream>
#include <string>

using namespace std;

void Game::SetUp()
{
	//Room Attributes
	int totalRooms;
	int state;
	int neighbors[4];

	//Creature Attributes
	int totalCreatures;
	int type;
	int location;

	// Set Up Rooms
	cin >> totalRooms;
	
	for (int i = 0; i < totalRooms; i++)
	{
		cin >> state;

		//4 Directions
		for (int i = 0; i < 4; i++)
		{
			cin >> neighbors[i];
		}
		Room* room = new Room();
		room->SetState(state);
		room->SetNeighbors(neighbors);
		
		rooms[i] = room;

		delete room;
	}
	//

	//Set Up Creatures
	cin >> totalCreatures;

	for (int i = 0; i < totalCreatures; i++)
	{
		cin >> type;
		cin >> location;

		Creature* creature = new Creature();
		creature->SetRoom(location);
		creature->SetType(type);

		creatures[i] = creature;

		delete creature;
	}
}

int Game::Play()
{
	Util* util = new Util;
	string command;
	//game loop
	do
	{
		cout << endl;
		cin >> command;

		if (command == "north") //player movement
		{
			printf("%s\n", "Player Movement North.");
			int curRoomIndex = player->GetRoom;
			Room* curRoom = rooms[curRoomIndex];
			int nextRoomIndex = curRoom->GetNeighbors()[0];
			player->SetRoom(nextRoomIndex);
		}

		else if (command == "west" ) //use ends with - break into player action, creature action
		{

		}
		else if (command == "south") //use ends with - break into player action, creature action
		{

		}
		else if (command == "east") //use ends with - break into player action, creature action
		{

		}
		else if (util->hasEnding(command, "clean")) //use ends with - break into player action, creature action
		{
			if (command == "clean")
			{
				printf("%s\n", "Player Clean.");
			}
			else
			{
				printf("%s\n", "Creature Clean.");
			}

		}
		else if (command == "help")
		{
			printf("%s\n", "Help not yet implemented.");
		}
		else if (command == "quit")
		{
			printf("%s\n", "Goodbye!");
		}
		else 
		{
			printf("%s\n", "Please enter a valid command. Use help for a list of valid commands.");
		}

	} while (command != "quit"); //exit game loop.
 

	return 0;
}