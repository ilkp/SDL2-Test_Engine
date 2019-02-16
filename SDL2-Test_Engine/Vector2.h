#pragma once
class Vector2
{
private:
	float components[2];

public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();
	float getX();
	float getY();
	void setX(float component);
	void setY(float component);
	Vector2 operator+(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	Vector2 operator/(const float divider);
	Vector2 operator*(const float multiplier);
	Vector2& operator=(const Vector2& other);

	float magnitude();

};

