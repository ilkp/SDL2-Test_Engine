#include "PlayerMovement.h"



PlayerMovement::PlayerMovement(PhysicsObject* player)
{
	this->player = player;
}


PlayerMovement::~PlayerMovement()
{
}

void PlayerMovement::update(int keyState[4])
{
	if (keyState[0] == 1)
	{
		player->translate(Vector2(0.0f, 1.0f));
	}
	if (keyState[1] == 1)
	{
		player->translate(Vector2(-1.0f, 0.0f));
	}
	if (keyState[2] == 1)
	{
		player->translate(Vector2(0.0f, -1.0f));
	}
	if (keyState[3] == 1)
	{
		player->translate(Vector2(1.0f, 0.0f));
	}
}