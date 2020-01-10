#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "graphic_object.hpp"

class Player : public GraphicObject
{
	sf::Vector2f velocity;
	sf::Vector2f defaultVelocity;
	bool canGoUp, canGoDown, canGoLeft, canGoRight;
	enum playerState { stand, goLeft, goRight, goUp, goDown, win, die};

public:
	void move(const sf::Time & deltaTime);

	void goUp(const sf::Time & deltaTime);

	void goDown(const sf::Time & deltaTime);

	void goLeft(const sf::Time & deltaTime);

	void goRight(const sf::Time & deltaTime);

};