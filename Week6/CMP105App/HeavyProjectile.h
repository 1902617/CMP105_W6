#pragma once
#include "Entity.h"

class HeavyProjectile : public Entity
{
public:
	HeavyProjectile();
	~HeavyProjectile();

	bool hasFired, mouseDown, ballSelected;
	sf::Vector2f mouseStartPos, mouseEndPos;

	void update(float dt, int wX, int wY);
	void handleInput(float dt, Input* i);
	void fireBall(float dt);
};