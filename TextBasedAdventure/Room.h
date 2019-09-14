#pragma once
class Room
{
private:
	int state = -1;
	int neighbors[4] = { -1,-1,-1,-1 };
public:
	Room();
	Room(int state, int neighbors[4]);

	int GetState();
	void SetState(int state);

	int* GetNeighbors();
	//void SetNeighbors(int neighbors[4]);
};

