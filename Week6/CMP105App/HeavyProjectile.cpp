#include "HeavyProjectile.h"
#include "Framework/Vector.h"
#include "iostream"

HeavyProjectile::HeavyProjectile()
{
	hasFired = false;
	mouseDown = false;
	ballSelected = false;
	mouseStartPos = sf::Vector2f(0.f, 0.f);
	mouseEndPos = sf::Vector2f(0.f, 0.f);
}

HeavyProjectile::~HeavyProjectile()
{

}

void HeavyProjectile::update(float dt, int wX, int wY)
{
	if (hasFired)
	{
		sf::Vector2f trajectory = (mouseStartPos - mouseEndPos);
		float force = (Vector::magnitude(trajectory) * 10);
		trajectory = Vector::normalise(trajectory);
		sf::Vector2f velocity = (trajectory * force);
		setPosition(getPosition() + (velocity * dt));

		Entity::update(dt, wX, wY);
	}
}

void HeavyProjectile::handleInput(float dt, Input* i)
{
	if (i->isMouseLDown() && !mouseDown)
	{
		mouseStartPos = sf::Vector2f(i->getMouseX(), i->getMouseY());
		

		if((mouseStartPos.x > (getPosition().x + getSize().x / 2) 
			|| mouseStartPos.x < (getPosition().x - getSize().x / 2)) 
				||(mouseStartPos.y > (getPosition().y + getSize().x / 2)
					|| mouseStartPos.y < (getPosition().y - getSize().x / 2)))
		{
			//std::cout << "You have to click on the ball!\n";
		}

		else
		{
			ballSelected = true;
			std::cout << "Ball Selected\n";
			mouseDown = true;
		}
	}

	if (mouseDown && ballSelected)
	{
		mouseEndPos = sf::Vector2f(i->getMouseX(), i->getMouseY());
		std::cout << "Drag In Progress\n";
	}

	if (!(i->isMouseLDown()) && mouseDown)
	{
		std::cout << "Ball Fired\n";
		mouseDown = false;
		hasFired = true;
	}
}