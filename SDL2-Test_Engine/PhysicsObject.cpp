#include "PhysicsObject.h"



PhysicsObject::PhysicsObject(bool isStatic)
{
	this->isStatic = isStatic;
	position = Vector2(0.0f, 0.0f);
	mass = 1.0f;
}

PhysicsObject::PhysicsObject(bool isStatic, std::string tag)
{
	this->isStatic = isStatic;
	position = Vector2(0.0f, 0.0f);
	mass = 1.0f;
	this->tag = tag;
}

PhysicsObject::PhysicsObject(bool isStatic, Vector2 position)
{
	this->isStatic = isStatic;
	this->position = position;
	mass = 1.0f;
}

PhysicsObject::PhysicsObject(bool isStatic, Vector2 position, float mass)
{
	this->isStatic = isStatic;
	this->position = position;
	this->mass = mass;
}

PhysicsObject::~PhysicsObject()
{
}



float* PhysicsObject::physicsObjectOut()
{
	return new float[5]{ mass, position.getX(), position.getY(), velocity.getX(), velocity.getY() };
}

void PhysicsObject::translate(Vector2 translation)
{
	position = position + translation;
}

void PhysicsObject::addForce(Vector2 force)
{
	forceVectors.push_front(force);
}

std::list<Vector2> PhysicsObject::getForceVectors()
{
	return forceVectors;
}

void PhysicsObject::clearForceVectors()
{
	forceVectors.clear();
}

void PhysicsObject::setHitbox(SDL_Point topLeft, SDL_Point topRight, SDL_Point botLeft, SDL_Point botRight)
{
	hitbox[0] = topLeft;
	hitbox[1] = topRight;
	hitbox[2] = botLeft;
	hitbox[3] = botRight;
}