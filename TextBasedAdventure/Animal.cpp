#include "Animal.h"

Animal::Animal()
{

}

void Animal::growl(int& respect)
{
	respect--;
}

void Animal::lickFace(int& respect)
{
	respect++;
}