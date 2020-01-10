#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "graphic_object.hpp"
#include "enum.hpp"

class Player : public GraphicObject
{
	sf::Vector2f velocity;
	sf::Vector2f defaultVelocity;
	bool canGoUp, canGoDown, canGoLeft, canGoRight;
	States playerState;

public:
	Player(bool up, bool down, bool right, bool left);

	void Move(const sf::Time & deltaTime);

	void GoUp(const sf::Time & deltaTime);

	void GoDown(const sf::Time & deltaTime);

	void GoLeft(const sf::Time & deltaTime);

	void GoRight(const sf::Time & deltaTime);

	void ForbidGoingLeft();

	void ForbidGoingRight();

	void ForbidGoingDown();

	void ForbidGoingUp();

	void Update(const sf::Time deltaTime);

	void UpdateSprite();

	void UpdateCollisionBox();

};