#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	
	// ----- Textures -----
	playerTexture.loadFromFile("gfx/ArcherSpriteSheet.png");
	
	// ----- Player -----
	player.setSize(sf::Vector2f(90, 120)); // 18 x 24 base (this is 5x)
	player.setPosition(300, 150);
	player.setTexture(&playerTexture);
	player.setInput(input);
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
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(player);

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