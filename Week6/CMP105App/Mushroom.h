#pragma once
#include "Entity.h"

class Mushroom : public Entity
{
public:
	Mushroom();
	~Mushroom();

	void update(float dt, int wX, int wY);
	void moveToTarget(float dt);

	float speed, scale;
	sf::Vector2f direction;
};