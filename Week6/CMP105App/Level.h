#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include "Player.h"
#include "Mushroom.h"
#include "Projectile.h"
#include "HeavyProjectile.h"
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	sf::Texture mushroomTexture;
	sf::Texture sphereTexture;

	Player player;
	Mushroom enemyA;
	Projectile sphereA;
	HeavyProjectile ballA;

	// More level variables#
};