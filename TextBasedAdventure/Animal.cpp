#include "Animal.h"
#include <stdio.h>

Animal::Animal()
{

}

void Animal::Growl(int& respect, int state)
{
	printf("%d %s", this->GetName(), "growls.");
	respect--;
}

void Animal::LickFace(int& respect, int state)
{
	printf("%d %s", this->GetName(), "licks your face.");
	respect++;
}

void Animal::StrongGrowl(int& respect, int state)
{
	printf("%d %s", this->GetName(), "growls a lot.");
	respect = respect - 3;
}

void Animal::StrongLickFace(int& respect, int state)
{
	printf("%d %s", this->GetName(), "licks your face a lot.");
	respect = respect + 3;
}

void Animal::React(int& respect, int state, int action)
{
	if (action == 0) //clean
	{
		if (state != 0)
			LickFace(respect, state);
	}
	else //dirty
	{
		if (state != 2)
			Growl(respect, state);
	}

	printf(" %s %d.\n", "Respect is now ", respect);
}

void Animal::StrongReact(int& respect, int state, int action)
{
	if (action == 0) //clean
	{
		if (state != 0)
			StrongLickFace(respect, state);
	}
	else //dirty
	{
		if (state != 2)
			StrongGrowl(respect, state);
	}

	printf(" %s %d.\n", "Respect is now ", respect);
}