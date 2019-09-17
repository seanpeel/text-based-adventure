#include "Npc.h"
#include <stdio.h>

Npc::Npc()
{

}

void Npc::grumble(int& respect, int state)
{
	if (state == 0)
	{
		printf("%s\n", "This room is already clean.");
	}
	else
	{
		respect--;
	}
}

void Npc::smile(int& respect, int state)
{
	if (state == 2)
	{
		printf("%s\n", "This room is already dirty.");
	}
	else
	{
		respect++;
	}
}

void Npc::React(int& respect, int state, int action)
{
	if (action == 0) //clean
	{
		grumble(respect, state);
	}
	else //dirty
	{
		smile(respect, state);
	}
}