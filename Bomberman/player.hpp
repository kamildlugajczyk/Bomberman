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

	void ForbidGoingLeft();

	void ForbidGoingRight();

	void ForbidGoingDown();

	void ForbidGoingUp();

	void Update(const sf::Time deltaTime);

	void UpdateSprite();

	void UpdateCollisionBox();

	sf::FloatRect collider;

	sf::FloatRect nextPosition;

	//bool IsColidingWithAnything();


	//void CheckForCollisions(const sf::Time & deltaTime, Map & map);

	bool CheckForCollisions(const sf::Time & deltaTime, Map & map);


};