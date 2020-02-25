#include "Projectile.h"

Projectile::Projectile()
{
	speed = 300.f;
	target = sf::Vector2f(500, 0);
}

Projectile::~Projectile()
{

}

void Projectile::update(float dt, int wX, int xY)
{
	direction = target - getPosition();
	direction = Vector::normalise(direction);
	velocity = (direction * speed);
	setPosition(getPosition() + (velocity*dt));

	if (Vector::magnitude(target - getPosition()) < 10.f)
	{
		setPosition(target);
	}
}

void Projectile::handleInput(float dt, Input* i)
{
	if (i->isMouseRDown())
	{
		target = sf::Vector2f(i->getMouseX(), i->getMouseY());
	}
}