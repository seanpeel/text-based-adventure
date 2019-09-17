#include "Npc.h"
#include <stdio.h>

Npc::Npc()
{

}

void Npc::Grumble(int& respect)
{
	printf("%d %s.", this->GetName(), "grumbles");
	respect--;
}

void Npc::Smile(int& respect)
{
	printf("%d %s.", this->GetName(), "smiles");
	respect++;
}

void Npc::StrongGrumble(int& respect)
{
	printf("%d %s.", this->GetName(), "grumbles a lot");
	respect = respect - 3;
}

void Npc::StrongSmile(int& respect)
{
	printf("%d %s.", this->GetName(), "smiles a lot");
	respect = respect + 3;
}

void Npc::React(int& respect, int state, int action)
{
	if (action == 0) //clean
	{
		if(state != 0)
			Grumble(respect);
		else
			printf("%s\n", "This room is already clean.");
	}
	else //dirty
	{
		if (state != 2)
			Smile(respect);
		else
			printf("%s\n", "This room is already dirty.");
	}

	printf(" %s %d.\n", "Respect is now ", respect);
}

void Npc::StrongReact(int& respect, int state, int action)
{
	if (action == 0) //clean
	{
		if (state != 0)
			StrongGrumble(respect);
		else
			printf("%s\n", "This room is already clean.");
	}
	else //dirty
	{
		if (state != 2)
			StrongSmile(respect);
		else
			printf("%s\n", "This room is already dirty.");
	}

	printf(" %s %d.\n", "Respect is now ", respect);
}