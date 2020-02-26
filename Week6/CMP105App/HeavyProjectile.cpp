#include "HeavyProjectile.h"
#include "Framework/Vector.h"
#include "iostream"

HeavyProjectile::HeavyProjectile()
{
	hasFired = false;													// Change when the ball is in a movement state.
	mouseDown = false;													// Tracks current mouse position.
	ballSelected = false;												// Change when the cursor has selected the balls position.
	mouseStartPos = sf::Vector2f(0.f, 0.f);								// Mouse's starting position when ball is clicked.
	mouseEndPos = sf::Vector2f(0.f, 0.f);								// End position for the mouse drag.
}

HeavyProjectile::~HeavyProjectile()
{

}

void HeavyProjectile::update(float dt, int wX, int wY)
{
	if (hasFired)														
	{
		sf::Vector2f trajectory = (mouseStartPos - mouseEndPos);		// Trajectory = direction the ball will be fired in.
		float force = (Vector::magnitude(trajectory) * 10);				// Force = how fast the ball will go (x10 as base magnitude is low). 
		trajectory = Vector::normalise(trajectory);						// Normalise the trajectory.
		sf::Vector2f velocity = (trajectory * force);					// Calculates the balls direction and speed.
		setPosition(getPosition() + (velocity * dt));					// Applies the movement to the ball.
						
		Entity::update(dt, wX, wY);										// Runs base's update that applies gravity.
	}
}

void HeavyProjectile::handleInput(float dt, Input* i)
{
	if (i->isMouseLDown() && !mouseDown)								// Checks for when the L mouse button is pressed		
	{
		mouseStartPos = sf::Vector2f(i->getMouseX(), i->getMouseY());

		if((mouseStartPos.x > (getPosition().x + getSize().x / 2)		// This checks that the player hasent clicked on the actual ball.
			|| mouseStartPos.x < (getPosition().x - getSize().x / 2)) 
				||(mouseStartPos.y > (getPosition().y + getSize().x / 2)
					|| mouseStartPos.y < (getPosition().y - getSize().x / 2)))
		{
			//std::cout << "You have to click on the ball!\n";
		}

		else															// Else the player must have clicked the ball.
		{
			ballSelected = true;		
			//std::cout << "Ball Selected\n";
			mouseDown = true;												
		}
	}

	if (mouseDown && ballSelected)										// If the mouse is down and on the ball.
	{
		mouseEndPos = sf::Vector2f(i->getMouseX(), i->getMouseY());		// Generate the end position to be the mouse's current position.
		std::cout << "Drag In Progress\n";
	}

	if (!(i->isMouseLDown()) && mouseDown)								// When the mouse is released in the drag phase.
	{
		std::cout << "Ball Fired\n";
		mouseDown = false;
		hasFired = true;						
	}
}