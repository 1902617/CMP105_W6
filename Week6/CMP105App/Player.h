#pragma once

#include "Entity.h"
#include "Framework/Animation.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	bool idleDir, isIdle;
	int windowX, windowY;
	sf::Vector2f jumpVector, mousePos;


	void update(float dt, int wX, int wY);
	void handleInput(float dt, Input* i);
	void idleLeft(float dt);
	void idleRight(float dt);
	void walkingRight(float dt);
	void walkingLeft(float dt);

protected:
	Animation walk;
	Animation idle;
};