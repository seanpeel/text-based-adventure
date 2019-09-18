#pragma once
class Room
{
private:
	int state = -1;
	int neighbors[4] = { -1,-1,-1,-1 };
	int creatures[10] = { -1 };
	int totalCreatures = 0;
public:
	Room();
	Room(int state, int neighbors[4]);

	int GetState();
	void SetState(int state);

	int* GetNeighbors();
	int* GetCreatures();
	int& GetTotalCreatures();
	void AddCreature(int creature);
	int RemoveCreature(int creature);

	void Clean();
	void Dirty();
};

