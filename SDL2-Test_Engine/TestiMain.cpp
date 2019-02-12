
#define SDL_MAIN_HANDLED
#include "Logic.h"
#include "include/SDL.h"
#include "..\SDL2-2.0.9\include\SDL.h"

#define SDL_MAIN_HANDLED

int main(int argc, char* argv[])
{
	int FPS = 60;
	int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameEnd = 0;

	Logic* game = new Logic();
	game->initialize(100, 100, 800, 600);

	while (!game->getUserQuit())
	{
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		frameEnd = SDL_GetTicks() - frameStart;

		if (frameEnd < frameDelay)
		{
			SDL_Delay(frameDelay - frameEnd);
		}
		game->setElapsedTime(SDL_GetTicks() - frameStart);
	}

	SDL_DestroyWindow(game->getWindow());
	SDL_Quit();

	return EXIT_SUCCESS;
}
