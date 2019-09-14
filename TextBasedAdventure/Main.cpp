#include "Game.h"

int main()
{
	Game* game = new Game;
	game->SetUp();
	game->Play();
	return 0;
}