#include "Player.h"

Player::Player()
{
	playerTexture.loadFromFile("gfx/ArcherSpriteSheet.png");

	setSize(sf::Vector2f(90, 120)); // 18 x 24 base (this is 5x)
	setPosition(300, 150);
	setTexture(&playerTexture);

	int y = 0, y2 = 25, w = 22, h = 25;

	// ----- Idle Animation -----
	for (int i = 0; i <= 221; i += 22)
	{
		idle.addFrame(sf::IntRect(i, y, w, h));
	}
	idle.setFrameSpeed(1.f / 2.f);

	// ----- Walk Animation -----
	for (int i = 0; i <= 177; i += 22)
	{
		walk.addFrame(sf::IntRect(i, y2, w, h));
	}
	walk.setFrameSpeed(1.f / 10.f);


	isIdle = true;
	idleDir = false;
	speed = 0.1f;
	mousePos.x = 0.f;
	mousePos.y = 0.f;


	// ----- Forces -----
	jumpVector = sf::Vector2f(0, -4.f) * Entity::scale;
}

Player::~Player()
{

}

void Player::update(float dt, int wX, int wY)
{
	Entity::update(dt, wX, wY);
	idleCheck(dt);
}


void Player::handleInput(float dt, Input* i)
{
	if (i->isKeyDown(sf::Keyboard::D))
	{
		isIdle = false;
		idleDir = false;
		walkingRight(dt);
		move(speed, 0);
	}

	if (i->isKeyDown(sf::Keyboard::A))
	{
		isIdle = false;
		idleDir = true;
		walkingLeft(dt);
		move(-speed, 0);
	}

	if (!i->isKeyDown(sf::Keyboard::D) && !i->isKeyDown(sf::Keyboard::A))
	{
		isIdle = true;
	}

	if (i->isKeyDown(sf::Keyboard::Space) && !isJumping)
	{
		stepVelocity = jumpVector;
		isJumping = true;
	}

	if (!i->isKeyDown(sf::Keyboard::Space))
	{
		velocity = sf::Vector2f(0, 0);
	}

	if (i->isMouseLDown())
	{
		mousePos.x = i->getMouseX();
		mousePos.y = i->getMouseY();
		setPosition(mousePos);
		stepVelocity = sf::Vector2f(0, 0);
	}
}

void Player::idleCheck(float dt)
{
	if (isIdle && idleDir)
	{
		for (int i = 0; i <= 4; i++)
		{
			idleLeft(dt);
		}
	}
	else if (isIdle && !idleDir)
	{
		for (int i = 0; i <= 4; i++)
		{
			idleRight(dt);
		}
	}
}

void Player::idleLeft(float dt)
{
	idle.setFlipped(true);
	idle.animate(dt);
	setTextureRect(idle.getCurrentFrame());
}

void Player::idleRight(float dt)
{
	idle.setFlipped(false);
	idle.animate(dt);
	setTextureRect(idle.getCurrentFrame());
}

void Player::walkingRight(float dt)
{
	walk.setFlipped(false);
	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
}

void Player::walkingLeft(float dt)
{
	walk.setFlipped(true);
	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
}