#pragma once
#include "Entity.h"

class Mushroom : public Entity
{
public:
	Mushroom();
	~Mushroom();

	void update(float dt, int wX, int wY);
	void handleInput(float dt, Input* i);
	void moveToTarget(float dt);

	float speed;
	sf::Vector2f direction, target;
};