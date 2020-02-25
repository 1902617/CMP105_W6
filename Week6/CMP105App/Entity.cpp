#include "Entity.h"


Entity::Entity()
{
	acceleration = 0.f;

	// ----- Forces -----
	scale = 200.f;
	gravity = sf::Vector2f(0, 9.8f) * scale;

	isJumping = false;
}

Entity::~Entity()
{

}

void Entity::update(float dt, int wX, int wY)
{
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; // ut + 1/2at^2
	stepVelocity += gravity * dt;
	setPosition(getPosition() + pos);

	if (getPosition().y >= wY - (getSize().y / 2))
	{
		isJumping = false;
		setPosition(getPosition().x, wY - (getSize().y / 2));
		stepVelocity = sf::Vector2f(0, 0);
	}
	/*
	if (getPosition().y <= 0 + (getSize().y / 2))
	{
		setPosition(getPosition().x, wY + (getSize().y / 2));
		stepVelocity = sf::Vector2f(0, 0);
	}

	if (getPosition().x >= wX - (getSize().x / 2))
	{
		setPosition(wX - (getSize().y / 2), getPosition().x);
		stepVelocity = sf::Vector2f(0, 0);
	}

	if (getPosition().x <= - + (getSize().x / 2))
	{
		setPosition(wX + (getSize().y / 2), getPosition().x);
		stepVelocity = sf::Vector2f(0, 0);
	}
	*/
}