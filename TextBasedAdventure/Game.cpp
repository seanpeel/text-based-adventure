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

		rooms[i] = new Room(state, neighbors);
	}
	//Done Setting up Rooms

	//Set Up Creatures
	cin >> totalCreatures;

	for (int i = 0; i < totalCreatures; i++)
	{
		cin >> type;
		cin >> location;

		switch (type)
		{
		case 0: // Player
			player = new Player();
			player->SetType(type);
			player->SetRoom(location);

			creatures[i] = player;
			break;
		case 1: // Animal
			{
				Animal* animal = new Animal();
				animal->SetType(type);
				animal->SetRoom(location);

				creatures[i] = animal;
				break;
			}
		case 2: // NPC 
			{
				Npc* npc = new Npc();
				npc->SetType(type);
				npc->SetRoom(location);

				creatures[i] = npc;
				break;
			}
		}
	}
	// Done Setting up Creatures
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
			int curRoomIndex = player->GetRoom();
			printf("%s%d\n", "Player Attempting to Move North. Current Room: ", curRoomIndex);
			Room* curRoom = rooms[curRoomIndex];
			int nextRoomIndex = curRoom->GetNeighbors()[NORTH];
			if(nextRoomIndex != -1) 
			{
				player->SetRoom(nextRoomIndex);
				printf("%s%d\n", "Player Moved North. Current Room: ", nextRoomIndex);
			}
			else
			{
				printf("%s\n", "No Room Exists to the North.");
			}
			
		}

		else if (command == "west" ) //player movement
		{
			int curRoomIndex = player->GetRoom();
			printf("%s%d\n", "Player Attempting to Move West. Current Room: ", curRoomIndex);
			Room* curRoom = rooms[curRoomIndex];
			int nextRoomIndex = curRoom->GetNeighbors()[WEST];
			if (nextRoomIndex != -1)
			{
				player->SetRoom(nextRoomIndex);
				printf("%s%d\n", "Player Moved West. Current Room: ", nextRoomIndex);
			}
			else
			{
				printf("%s\n", "No Room Exists to the West.");
			}
		}

		else if (command == "south") //player movement
		{
			int curRoomIndex = player->GetRoom();
			printf("%s%d\n", "Player Attempting to Move South. Current Room: ", curRoomIndex);
			Room* curRoom = rooms[curRoomIndex];
			int nextRoomIndex = curRoom->GetNeighbors()[SOUTH];
			if (nextRoomIndex != -1)
			{
				player->SetRoom(nextRoomIndex);
				printf("%s%d\n", "Player Moved South. Current Room: ", nextRoomIndex);
			}
			else
			{
				printf("%s\n", "No Room Exists to the South.");
			}
		}

		else if (command == "east") //player movement
		{
			int curRoomIndex = player->GetRoom();
			printf("%s%d\n", "Player Attempting to Move East. Current Room: ", curRoomIndex);
			Room* curRoom = rooms[curRoomIndex];
			int nextRoomIndex = curRoom->GetNeighbors()[EAST];
			if (nextRoomIndex != -1)
			{
				player->SetRoom(nextRoomIndex);
				printf("%s%d\n", "Player Moved East. Current Room: ", nextRoomIndex);
			}
			else
			{
				printf("%s\n", "No Room Exists to the East.");
			}
		}

		else if (util->hasEnding(command, "clean")) //use hasEnding - break into player action, creature action
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

		else if (util->hasEnding(command, "dirty")) //use hasEnding - break into player action, creature action
		{
			if (command == "dirty")
			{
				printf("%s\n", "Player Dirty.");
			}
			else
			{
				printf("%s\n", "Creature Dirty.");
			}

		}

		else if (command == "look")
		{
			int curRoomIndex = player->GetRoom();
			Room* curRoom = rooms[curRoomIndex];
			int* neighbors = curRoom->GetNeighbors();
			printf("Room: %d\nState: %d\n", curRoomIndex, rooms[curRoomIndex]->GetState());
			printf("%s %d %d %d %d\n", "Neighbors: ", neighbors[0], neighbors[1], neighbors[2], neighbors[3]);
		}

		else if (command == "help")
		{
			printf("%s\n", "Available commands are: north, west, south, east, look, clean, dirty, {creature}:clean, {creature}:dirty");
		}

		else if (command == "quit")
		{
			printf("%s\n", "Goodbye!");
		}

		else 
		{
			printf("%s\n", "Please enter a valid command. Use help for a list of valid commands.");
		}

		//player->GetRespect() >= 80 //You Win!
		//player->GetRespect() <= 0  //You Lose!


	} while (command != "quit"); //exit game loop.
 

	return 0;
}