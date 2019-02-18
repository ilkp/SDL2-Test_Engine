#include "Physics.h"
#include "Vector2.h"


Physics::Physics()
{
}


Physics::~Physics()
{
}

void Physics::calcPhysics(const unsigned elapsedTime, std::list<PhysicsObject*> physicsObjects)
{
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

void Physics::handleCollisions(std::list<PhysicsObject*> objects)
{
	float myStartX, myEndX, myStartY, myEndY, otherStartX, otherEndX, otherStartY, otherEndY;
	float penDepthX = 0.0f;
	float penDepthY = 0.0f;
	int penDirectionX = 0;
	int penDirectionY = 0;
	for (auto it = objects.begin(); it != objects.end(); it++)
	{
		if (!(*it)->getIsStatic())
		{
			myStartX = (*it)->getPosition().getX() + (*it)->getHitbox()[TOP_LEFT].x;
			myStartY = (*it)->getPosition().getY() + (*it)->getHitbox()[TOP_LEFT].y;
			myEndX = (*it)->getPosition().getX() + (*it)->getHitbox()[BOTTOM_RIGHT].x;
			myEndY = (*it)->getPosition().getY() + (*it)->getHitbox()[BOTTOM_RIGHT].y;
			auto it2 = it;
			it2++;
			for (; it2 != objects.end(); it2++)
			{
				otherStartX = (*it2)->getPosition().getX() + (*it)->getHitbox()[TOP_LEFT].x;
				otherStartY = (*it2)->getPosition().getY() + (*it)->getHitbox()[TOP_LEFT].y;
				otherEndX = (*it2)->getPosition().getX() + (*it)->getHitbox()[BOTTOM_RIGHT].x;
				otherEndY = (*it2)->getPosition().getY() + (*it)->getHitbox()[BOTTOM_RIGHT].y;
				if (!(myStartX > otherEndX || myEndX < otherStartX || myStartY > otherEndY || myEndY < otherStartY))
				{
					if ((*it)->getVelocity().getX() > 0)
					{
						penDepthX = myEndX - otherStartX;
						penDirectionX = -1;
					}
					else if ((*it)->getVelocity().getX() < 0) {
						penDepthX = otherEndX - myStartX;
						penDirectionX = 1;
					}
					if ((*it)->getVelocity().getY() > 0)
					{
						penDepthY = myEndY - otherStartY;
						penDirectionY = -1;
					}
					else if ((*it)->getVelocity().getY() < 0) {
						penDepthY = otherEndY - myStartY;
						penDirectionY = 1;
					}
					if (penDepthX < penDepthY)
					{
						(*it)->setPosition(Vector2((*it)->getPosition().getX() + (penDirectionX * penDepthX)
							, (*it)->getPosition().getY()));
						(*it)->setVelocity(Vector2(0.0f, (*it)->getVelocity().getY()));
					}
					else {
						(*it)->setPosition(Vector2((*it)->getPosition().getX()
							, (*it)->getPosition().getY() + (penDirectionY * penDepthY)));
						(*it)->setVelocity(Vector2((*it)->getVelocity().getX(), 0.0f));
					}

					std::cout << "HIT" << std::endl;
				}
				else {
					std::cout << "-" << std::endl;
				}
			}
		}
	}
}
