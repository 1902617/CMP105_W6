#include "Mushroom.h"

Mushroom::Mushroom()
{
	speed = 300.f;
	target = sf::Vector2f(500, 0);
}

Mushroom::~Mushroom()
{

}

void Mushroom::update(float dt, int wX, int wY)
{
	Entity::update(dt, wX, wY);
	moveToTarget(dt);
	target.y = wY;
}

void Mushroom::handleInput(float dt, Input* i)
{
	if (i->isMouseRDown())
	{
		target.x = i->getMouseX();
	}
}

void Mushroom::moveToTarget(float dt)
{
	if (getPosition().x > target.x)
	{
		move(-speed * dt, 0);
	}

	if (getPosition().x < target.x)
	{
		move(speed * dt, 0);
	}
}