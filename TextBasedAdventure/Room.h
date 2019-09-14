#pragma once
class Room
{
private:
	int state;
	int neighbors[4];
public:
	int GetState();
	void SetState(int state);

	int* GetNeighbors();
	void SetNeighbors(int neighbors[4]);
};

