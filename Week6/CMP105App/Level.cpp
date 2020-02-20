#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	
	// ----- Textures -----
	mushroomTexture.loadFromFile("gfx/Mushroom.png");
	
	// ----- Player -----
	player.setInput(input);

	// ----- Enemies -----
	enemyA.setTexture(&mushroomTexture);
	enemyA.setPosition(10, 10);
	enemyA.setSize(sf::Vector2f(30, 30));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player.handleInput(dt, input);
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt, window->getSize().x, window->getSize().y);
	enemyA.update(dt, window->getSize().x, window->getSize().y);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(player);
	window->draw(enemyA);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}