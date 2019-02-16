
#include <math.h>
#include "Vector2.h"



Vector2::Vector2()
{

}

Vector2::Vector2(float x, float y)
{
	components[0] = x;
	components[1] = y;
}


Vector2::~Vector2()
{
}

float Vector2::getX()
{
	return this->components[0];
}

float Vector2::getY()
{
	return this->components[1];
}

void Vector2::setX(float component)
{
	components[0] = component;
}

void Vector2::setY(float component)
{
	components[1] = component;
}

Vector2 Vector2::operator+(const Vector2& other)
{
	Vector2 newVector;
	newVector.components[0] = this->components[0] + other.components[0];
	newVector.components[1] = this->components[1] + other.components[1];
	return newVector;
}

Vector2 Vector2::operator-(const Vector2& other)
{
	Vector2 newVector;
	newVector.components[0] = this->components[0] - other.components[0];
	newVector.components[1] = this->components[1] - other.components[1];
	return newVector;
}

Vector2 Vector2::operator/(const float divider)
{
	Vector2 newVector;
	newVector.components[0] = this->components[0] / divider;
	newVector.components[1] = this->components[1] / divider;
	return newVector;
}

Vector2 Vector2::operator*(const float multiplier)
{
	Vector2 newVector;
	newVector.components[0] = this->components[0] * multiplier;
	newVector.components[1] = this->components[1] * multiplier;
	return newVector;
}

Vector2& Vector2::operator=(const Vector2& other)
{
	this->components[0] = other.components[0];
	this->components[1] = other.components[1];
	return *this;
}

float Vector2::magnitude()
{
	return sqrtf(components[0] * components[0] + components[1] * components[1]);
}