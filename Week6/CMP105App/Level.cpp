#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	
	// ----- Textures -----
	mushroomTexture.loadFromFile("gfx/Mushroom.png");
	sphereTexture.loadFromFile("gfx/Beach_Ball.png");
	
	// ----- Player -----
	player.setInput(in);

	// ----- Enemies -----
	enemyA.setTexture(&mushroomTexture);
	enemyA.setPosition(10, 10);
	enemyA.setSize(sf::Vector2f(30, 30));
	enemyA.setOrigin(enemyA.getSize().x / 2, enemyA.getSize().y / 2);
	enemyA.setInput(in);

	// ----- Projectiles -----
	sphereA.setPosition(30, 30);
	sphereA.setSize(sf::Vector2f(30, 30));
	sphereA.setOrigin(sphereA.getSize().x / 2, sphereA.getSize().y / 2);
	sphereA.setTexture(&sphereTexture);
	sphereA.setInput(in);

	ballA.setPosition(300, 350);
	ballA.setSize(sf::Vector2f(30, 30));
	ballA.setOrigin(ballA.getSize().x / 2, ballA.getSize().y / 2);
	ballA.setTexture(&sphereTexture);
	ballA.setInput(in);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player.handleInput(dt, input);
	enemyA.handleInput(dt, input);
	sphereA.handleInput(dt, input);
	ballA.handleInput(dt, input);
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt, window->getSize().x, window->getSize().y);
	enemyA.update(dt, window->getSize().x, window->getSize().y);
	sphereA.update(dt, window->getSize().x, window->getSize().y);
	ballA.update(dt, window->getSize().x, window->getSize().y);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(player);
	window->draw(enemyA);
	window->draw(sphereA);
	window->draw(ballA);

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