#pragma once
#include <list>
#include "Vector2.h"
#include <string>

class PhysicsObject
{
private:
	std::string tag;
	float mass;
	Vector2 position;
	Vector2 velocity;
	std::list<Vector2> forceVectors;

public:
	PhysicsObject();
	PhysicsObject(std::string tag);
	PhysicsObject(Vector2 position);
	PhysicsObject(Vector2 position, float mass);
	~PhysicsObject();

	float* physicsObjectOut();

	Vector2 getPosition();
	void setPosition(Vector2 position);
	float getX();
	float getY();
	float getMass();
	Vector2 getVelocity();
	void setVelocity(Vector2 velocity);
	void setMass(float mass);

	void translate(Vector2 transalation);
	void addForce(Vector2 force);
	std::list<Vector2> getForceVectors();
	void clearForceVectors();
	void setTag(std::string tag) { this->tag = tag; }
	std::string getTag() { return tag; }
};

