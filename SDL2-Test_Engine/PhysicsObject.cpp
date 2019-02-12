#include "PhysicsObject.h"



PhysicsObject::PhysicsObject()
{
	position = Vector2(0.0f, 0.0f);
	mass = 1.0f;
}

PhysicsObject::PhysicsObject(std::string tag)
{
	position = Vector2(0.0f, 0.0f);
	mass = 1.0f;
	this->tag = tag;
}

PhysicsObject::PhysicsObject(Vector2 position)
{
	this->position = position;
	mass = 1.0f;
}

PhysicsObject::PhysicsObject(Vector2 position, float mass)
{
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

Vector2 PhysicsObject::getPosition()
{
	return position;
}

void PhysicsObject::setPosition(Vector2 newPosition)
{
	position = newPosition;
}

float PhysicsObject::getX()
{
	return position.getX();
}

float PhysicsObject::getY()
{
	return position.getY();
}

float PhysicsObject::getMass()
{
	return mass;
}

Vector2 PhysicsObject::getVelocity()
{
	return velocity;
}

void PhysicsObject::setVelocity(Vector2 newVelocity)
{
	velocity = newVelocity;
}

void PhysicsObject::setMass(float mass)
{
	this->mass = mass;
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
