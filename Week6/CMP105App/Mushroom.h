#pragma once
#include "Framework/GameObject.h"

class Mushroom : public GameObject
{
public:
	Mushroom();
	~Mushroom();

	void update(float dt) override;

	float speed, scale, acceleration;
	int windowX, windowY;
	sf::Vector2f gravity, direction, velocity, stepVelocity, jumpVector;

	sf::Texture mushTexture;
};