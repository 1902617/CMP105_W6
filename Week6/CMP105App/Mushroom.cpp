#include "Mushroom.h"

Mushroom::Mushroom()
{
	scale = 0;
	speed = 0;
}

Mushroom::~Mushroom()
{

}

void Mushroom::update(float dt, int wX, int wY)
{
	Entity::update(dt, wX, wY);
	moveToTarget(dt);
}

void Mushroom::moveToTarget(float dt)
{

}