#pragma once

#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class Projectile : public GameObject
{
public:
	Projectile();
	~Projectile();

	float speed;
	sf::Vector2f velocity, target, movement, direction;

	void update(float dt, int wX, int xY);
	void handleInput(float dt, Input* i);
};