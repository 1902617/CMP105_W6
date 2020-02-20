#include "Entity.h"


Entity::Entity()
{
	windowX = 0;
	windowY = 0;
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

	if (getPosition().y >= windowY - getSize().y)
	{
		isJumping = false;
		setPosition(getPosition().x, windowY - getSize().y);
		stepVelocity = sf::Vector2f(0, 0);
	}
}