#pragma once
#include <list>
#include "..\SDL2-2.0.9\include\SDL.h"
#include "PhysicsObject.h"
#include "include/SDL.h"
#include "PlayerMovement.h"

class Logic
{
private:
	bool userQuit = false;
	PlayerMovement* playerMovement;
	Vector2 origo;
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::list<PhysicsObject*> physicsObjects = {};
	SDL_Rect player;
	unsigned elapsedTime = 0;
	float gravity = 9.81f;
	float gravityScale = 1.0f;
	int keyFlags[4] = { 0, 0, 0, 0 };

public:
	Logic();
	~Logic();
	int initialize(int xPos, int yPos, int width, int height);
	void update();
	void handleEvents();
	void render();
	bool getUserQuit() { return userQuit; }

	SDL_Window* getWindow() { return window; }
	void setElapsedTime(const unsigned time) { elapsedTime = time; }
};

