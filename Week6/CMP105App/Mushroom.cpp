#include "Mushroom.h"

Mushroom::Mushroom()
{
	mushTexture.loadFromFile("gfx/Mushroom.png");
	setPosition(10, 10);
	setScale(30, 30);
	setTexture(&mushTexture);
}

Mushroom::~Mushroom()
{

}

void Mushroom::update(float dt)
{

}