#pragma once
#include <string>
#include <list>
#include "Vector2.h"
#include "include/SDL.h"

enum hitboxLoc {
	TOP_LEFT = 0,
	TOP_RIGHT = 1,
	BOTTOM_LEFT = 2,
	BOTTOM_RIGHT = 3
};

class PhysicsObject
{
private:
	bool isStatic;
	std::string tag;
	float mass;
	Vector2 position;
	Vector2 velocity;
	std::list<Vector2> forceVectors;
	SDL_Point hitbox[4];

public:
	PhysicsObject(bool isStatic);
	PhysicsObject(bool isStatic, std::string tag);
	PhysicsObject(bool isStatic, Vector2 position);
	PhysicsObject(bool isStatic, Vector2 position, float mass);
	~PhysicsObject();

	float* physicsObjectOut();
	void translate(Vector2 transalation);
	void addForce(Vector2 force);
	std::list<Vector2> getForceVectors();
	void clearForceVectors();



	Vector2 getPosition() { return position; }
	void setPosition(Vector2 position) { this->position = position; }
	float getMass() { return mass; }
	void setMass(float mass) { this->mass = mass; }
	Vector2 getVelocity() { return velocity; }
	void setVelocity(Vector2 velocity) { this->velocity = velocity; }
	void setTag(std::string tag) { this->tag = tag; }
	std::string getTag() { return tag; }
	SDL_Point* getHitbox() { return hitbox; }
	void setHitbox(SDL_Point topLeft, SDL_Point topRight, SDL_Point botLeft, SDL_Point botRight);
	bool getIsStatic() { return isStatic; }
};

