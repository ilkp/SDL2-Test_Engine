#include "Logic.h"

#include <iostream>

Logic::Logic()
{
}

Logic::~Logic()
{
}

int Logic::initialize(int xPos, int yPos, int width, int height)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stderr, "Could not initialize sdl2: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	window = SDL_CreateWindow("Testi",
		xPos, yPos,
		width, height,
		SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr) {
		SDL_DestroyWindow(window);
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	player.w = 20;
	player.h = 20;
	origo = Vector2(width / 2, height / 2);
	physicsObjects.push_back(new PhysicsObject(Vector2(0.0f, 0.0f), 80.0f));
	physicsObjects.front()->setTag("player");

	playerMovement = new PlayerMovement(physicsObjects.front());

	return 0;
}

void Logic::handleEvents()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_KEYUP:
			switch (e.key.keysym.sym)
			{
			case SDLK_DOWN:
				keyFlags[0] = 0;
				break;
			case SDLK_UP:
				keyFlags[2] = 0;
				break;
			case SDLK_LEFT:
				keyFlags[1] = 0;
				break;
			case SDLK_RIGHT:
				keyFlags[3] = 0;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
			case SDLK_DOWN:
				keyFlags[0] = 1;
				break;
			case SDLK_UP:
				keyFlags[2] = 1;
				break;
			case SDLK_LEFT:
				keyFlags[1] = 1;
				break;
			case SDLK_RIGHT:
				keyFlags[3] = 1;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

void Logic::update()
{
	playerMovement->update(keyFlags);
	Vector2 forceSum;
	Vector2 acceleration;
	Vector2 newVelocity;
	std::list<Vector2> forceVectors;
	float* objectParameters;
	float elapsedTimef = elapsedTime / 1000.0f;
	for (auto it = physicsObjects.begin(); it != physicsObjects.end(); it++)
	{
		objectParameters = (*it)->physicsObjectOut();
		// objectParameters:
		// 0 -> mass
		// 1 -> position X
		// 2 -> position Y
		// 3 -> velocity X
		// 4 -> velocity Y
		forceSum = Vector2(0.0f, 0.0f);
		forceVectors = (*it)->getForceVectors();
		for (Vector2 forceVector : forceVectors) {
			forceSum = forceSum + forceVector;
		}
		acceleration = forceSum / objectParameters[0];
		newVelocity = Vector2(objectParameters[3], objectParameters[4]) + acceleration * elapsedTimef;
		(*it)->setVelocity(newVelocity);
		(*it)->translate(newVelocity * 200.0f);

		delete[](objectParameters);
		(*it)->clearForceVectors();
	}
	
}

void Logic::render()
{
	SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	player.x = int(origo.getX() + physicsObjects.front()->getPosition().getX());
	player.y = int(origo.getY() + physicsObjects.front()->getPosition().getY());
	SDL_RenderDrawRect(renderer, &player);
	SDL_RenderPresent(renderer);
}