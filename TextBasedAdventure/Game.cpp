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
	player = new Player();
	cin >> totalCreatures;

	for (int i = 0; i < totalCreatures; i++)
	{
		cin >> type;
		cin >> location;

		switch (type)
		{
		case 0: // Player
			player->SetType(type);
			player->SetRoom(location);

			creatures[i] = player;
			playerIndex = i;
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
		creatures[i]->SetName(i);
		rooms[location]->AddCreature(i);
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
			Room* curRoom = rooms[curRoomIndex];
			int nextRoomIndex = curRoom->GetNeighbors()[NORTH];
			int success = player->Move(playerIndex, curRoomIndex, nextRoomIndex, rooms);

			if (success == 0)
			{
				printf("%s\n\n", "You leave towards the north.");
			}
			else
			{
				printf("%s\n\n", "No room exists to the north.");
			}
			
		}

		else if (command == "west" ) //player movement
		{
			int curRoomIndex = player->GetRoom();
			Room* curRoom = rooms[curRoomIndex];
			int nextRoomIndex = curRoom->GetNeighbors()[WEST];
			int success = player->Move(playerIndex, curRoomIndex, nextRoomIndex, rooms);

			if (success == 0)
			{
				printf("%s\n\n", "You leave towards the west.");
			}
			else
			{
				printf("%s\n\n", "No room exists to the west.");
			}
		}

		else if (command == "south") //player movement
		{
			int curRoomIndex = player->GetRoom();
			Room* curRoom = rooms[curRoomIndex];
			int nextRoomIndex = curRoom->GetNeighbors()[SOUTH];
			int success = player->Move(playerIndex, curRoomIndex, nextRoomIndex, rooms);
			if (success == 0)
			{
				printf("%s\n\n", "You leave towards the south.");
			}
			else
			{
				printf("%s\n\n", "No room exists to the south.");
			}
		}

		else if (command == "east") //player movement
		{
			int curRoomIndex = player->GetRoom();
			Room* curRoom = rooms[curRoomIndex];
			int nextRoomIndex = curRoom->GetNeighbors()[EAST];
			int success = player->Move(playerIndex, curRoomIndex, nextRoomIndex, rooms);
			if (success == 0)
			{
				printf("%s\n\n", "You leave towards the east.");
			}
			else
			{
				printf("%s\n\n", "No room exists to the east.");
			}
		}

		else if (util->hasEnding(command, "clean")) //use hasEnding - break into player action, creature action
		{
			int* respect = player->GetRespect();
			int curRoomIndex = player->GetRoom();
			Room* curRoom = rooms[curRoomIndex];
			int* creaturesIndex = curRoom->GetCreatures();
			int totalCreatures = curRoom->GetTotalCreatures();
			int state = curRoom->GetState();
			
			curRoom->Clean();
			
			for (int i = 0; i < totalCreatures; i++)
			{
				Creature* creature = creatures[creaturesIndex[i]];
				int type = creature->GetType();

				switch (type)
				{
				case 1:
					//cast to Animal;
					if(command == "clean")
						static_cast<Animal*>(creature)->React(*respect, state, CLEAN); //player clean reaction
					else
						static_cast<Animal*>(creature)->StrongReact(*respect, state, CLEAN); //creature clean reaction
					break;
				case 2:
					//cast to Npc;
					if (command == "clean")
						static_cast<Npc*>(creature)->React(*respect, state, CLEAN); //player clean reaction
					else
						static_cast<Npc*>(creature)->StrongReact(*respect, state, CLEAN); //creature clean reaction
					break;
				}
			}
		}

		else if (util->hasEnding(command, "dirty")) //use hasEnding - break into player action, creature action
		{
			int* respect = player->GetRespect();
			int curRoomIndex = player->GetRoom();
			Room* curRoom = rooms[curRoomIndex];
			int* creaturesIndex = curRoom->GetCreatures();
			int totalCreatures = curRoom->GetTotalCreatures();
			int state = curRoom->GetState();

			curRoom->Dirty();

			for (int i = 0; i < totalCreatures; i++)
			{
				Creature* creature = creatures[creaturesIndex[i]];
				int type = creature->GetType();

				switch (type)
				{
				case 1:
					//cast to Animal;
					if (command == "dirty")
						static_cast<Animal*>(creature)->React(*respect, state, DIRTY); //player dirty reaction
					else
						static_cast<Animal*>(creature)->StrongReact(*respect, state, DIRTY); //creature dirty reaction
					break;
				case 2:
					//cast to Npc;
					if (command == "dirty")
						static_cast<Npc*>(creature)->React(*respect, state, DIRTY); //player dirty reaction
					else
						static_cast<Npc*>(creature)->StrongReact(*respect, state, DIRTY); //creature dirty reaction
					break;
				}
			}
		}

		else if (command == "look")
		{
			int curRoomIndex = player->GetRoom();
			Room* curRoom = rooms[curRoomIndex];
			int* neighbors = curRoom->GetNeighbors();

			printf("Room %d, ", curRoomIndex);
			
			string roomState = "";
			switch (rooms[curRoomIndex]->GetState())
			{
			case 0:
				roomState = "clean";
				break;
			case 1:
				roomState = "half-dirty";
				break;
			case 2:
				roomState = "dirty";
				break;
			}
			cout << roomState << ", Neighbors";

			for(int i = 0; i < 4; i++) 
			{
				if (neighbors[i] != -1)
				{
					switch (i)
					{
					case 0:
						printf(" %d %s", neighbors[i], "to the north");
						break;
					case 1:
						printf(" %d %s", neighbors[i], "to the south");
						break;
					case 2:
						printf(" %d %s", neighbors[i], "to the east");
						break;
					case 3:
						printf(" %d %s", neighbors[i], "to the west");
						break;
					}
				}
			}

			printf(", %s\n", "contains:");

			int totalCreaturesInRoom = curRoom->GetTotalCreatures();

			if (totalCreaturesInRoom > 0)
			{
				int* creaturesInRoom = curRoom->GetCreatures();

				for (int i = 0; i < totalCreaturesInRoom; i++)
				{
					Creature* curCreature = creatures[creaturesInRoom[i]];
					int curCreatureType = curCreature->GetType();
					switch (curCreatureType)
					{
					case 0: // Player
						printf("%s\n", "PC");
						break;
					case 1: // Animal
						printf("%s %d\n", "animal", creaturesInRoom[i]);
						break;
					case 2: // NPC
						printf("%s %d\n", "human", creaturesInRoom[i]);
						break;
					}
				}
			}
		}

		else if (command == "help")
		{
			printf("%s\n", "Available commands are: north, west, south, east, look, clean, dirty, {creature}:clean, {creature}:dirty");
		}

		else if (command == "exit")
		{
			printf("%s\n", "Goodbye!");
		}

		else if (*player->GetRespect() >= 80)
		{
			printf("%s\n\n", "You Win!");
			exit;
		}

		else if (*player->GetRespect() <= 0)
		{
			printf("%s\n\n", "You Lose!");
			exit;
		}

		else 
		{
			printf("%s\n", "Please enter a valid command. Use \"help\" for a list of valid commands.");
		}

	} while (command != "exit"); //exit game loop.
 

	return 0;
}