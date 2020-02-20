#pragma once

#include "Framework/GameObject.h"

class Entity : public GameObject
{
public:

	Entity();
	~Entity();

	float scale, acceleration;
	bool isJumping;
	sf::Vector2f gravity, velocity, stepVelocity;


	void update(float dt, int wX, int wY);
};