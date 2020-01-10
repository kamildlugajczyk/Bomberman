#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "player.hpp"


Player::Player(bool up, bool down, bool right, bool left)
	: canGoUp(up), canGoDown(down), canGoRight(right), canGoLeft(left)
{
	defaultVelocity = { 200.f, 200.f };
	velocity = defaultVelocity;

	collisionBox.width = 50;
	collisionBox.height = 50;

	playerState = stand;
}

void Player::Move(const sf::Time & deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		GoUp(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		GoDown(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		GoLeft(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		GoRight(deltaTime);
}

void Player::GoUp(const sf::Time & deltaTime)
{
	if (canGoUp)
	{
		position.y -= velocity.y * deltaTime.asSeconds();
		playerState = movingUp;
	}
}

void Player::GoDown(const sf::Time & deltaTime)
{
	if (canGoDown)
	{
		position.y += velocity.y * deltaTime.asSeconds();
		playerState = movingDown;
	}
}

void Player::GoLeft(const sf::Time & deltaTime)
{
	if (canGoLeft)
	{
		position.x -= velocity.x * deltaTime.asSeconds();
		playerState = movingLeft;
	}
}

void Player::GoRight(const sf::Time & deltaTime)
{
	if (canGoRight)
	{
		position.x += velocity.x * deltaTime.asSeconds();
		playerState = movingRight;
	}
}

void Player::ForbidGoingLeft()
{
	this->canGoLeft = false;
}

void Player::ForbidGoingRight()
{
	this->canGoRight = false;
}

void Player::ForbidGoingDown()
{
	this->canGoDown = false;
}

void Player::ForbidGoingUp()
{
	this->canGoUp = false;
}

void Player::Update(const sf::Time deltaTime)
{
	UpdateSprite();
	sprite.setPosition(position);
}

void Player::UpdateSprite()
{
	/*sprite.setTextureRect(sf::IntRect(0, 0, 80, 120));
	sprite.setScale(0.5, 0.5);*/
	switch (playerState)
	{
	case stand:
		
		sprite.setTextureRect(sf::IntRect(0, 0, 80, 120));
		sprite.setScale(0.5, 0.5);
		/* Tekstura stania */
		break;
	case movingLeft:
		/* Tekstura w lewo */
		break;
	case movingRight:
		/* Tekstura w prawo */
		break;
	case movingUp:
		/* Tekstura z tylu */
		break;
	case movingDown:
		/* Tekstura z przodu */
		break;
	/*case win:										// te raczej nie
		break;
	case die:
		break;*/
	}
}

void Player::UpdateCollisionBox()									//zastanowic sie
{
	collisionBox.left = position.x - 1;
	collisionBox.top = position.y - 1;
}
