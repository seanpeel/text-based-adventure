#pragma once
class Creature
{
private:
	int type = -1;
	int room = -1;
public:
	Creature(int type, int room);
	Creature();

	int GetType();
	void SetType(int type);
	int GetRoom();
	void SetRoom(int room);
};

