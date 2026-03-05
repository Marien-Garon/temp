#include "Game.h"




int main(int argc, char* argv[])
{
	Game newGame;

	if (newGame.init())
	{
		newGame.loop();
		newGame.Close();
	}

	return 0;
}
