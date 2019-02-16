#pragma once
#include <vector>
#include <list>
#include <iostream>
#include "PhysicsObject.h"

class Physics
{
private:

public:
	Physics();
	~Physics();
	void calcPhysics(const unsigned elapsedTime, std::list<PhysicsObject*> physicsObjects);
	void handleCollisions(std::list<PhysicsObject*> objects);
};

