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

	void MoveArrows(const sf::Time & deltaTime, Map & map);

	void GoUp(const sf::Time & deltaTime, Map & map);

	void GoDown(const sf::Time & deltaTime, Map & map);

	void GoLeft(const sf::Time & deltaTime, Map & map);

	void GoRight(const sf::Time & deltaTime, Map & map);

	//--
	void ForbidGoingLeft() { canGoLeft = false; };

	void ForbidGoingRight() { canGoRight = false; };

	void ForbidGoingDown() { canGoDown = false; };

	void ForbidGoingUp() { canGoUp = false; };

	void AllowGoingLeft() { canGoLeft = true; };

	void AllowGoingRight() { canGoRight = true; };

	void AllowGoingDown() { canGoDown = true; };

	void AllowGoingUp() { canGoUp = true; };
	//--

	void Update(const sf::Time deltaTime);

	void UpdateSprite();

	sf::FloatRect GetCollisionBox() { return collisionBox; };

	void UpdateCollisionBox();

	void CheckForCollisions(const sf::Time & deltaTime, Map & map);

	//-------------
	bool killed = false;

	bool IsKilled() { return killed; };

	void Kill() { killed = true; };
};