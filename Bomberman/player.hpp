#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "graphic_object.hpp"
#include "enum.hpp"
#include "bomb.hpp"
#include "map.hpp"

class Player : public GraphicObject
{
	sf::Vector2f velocity;
	sf::Vector2f defaultVelocity;
	States playerState;

	bool canGoUp, canGoDown, canGoLeft, canGoRight;
	float timeSinceBomb, bombCooldown;

public:
	Player(bool up, bool down, bool right, bool left);

	void MoveWSAD(const sf::Time & deltaTime, Map & map);

	void MoveArrows(const sf::Time & deltaTime);

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

	void PlaceBomb(const sf::Time deltaTime);
};