#pragma once
#include "PhysicsObject.h"
#include "Vector2.h"
class PlayerMovement
{
private:
	PhysicsObject* player;

public:
	PlayerMovement(PhysicsObject* player);
	~PlayerMovement();
	void update(int keyState[4]);
};

