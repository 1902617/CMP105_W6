#pragma once

#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Entity : public GameObject
{
public:

	Entity();
	~Entity();

	float scale, acceleration;
	bool isJumping;
	int windowX, windowY;
	sf::Vector2f gravity, direction, velocity, stepVelocity;


	void update(float dt, int wX, int wY);
};