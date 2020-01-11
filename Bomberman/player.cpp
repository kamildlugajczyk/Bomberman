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

	sprite.setOrigin(16, 24);
}

void Player::MoveWSAD(const sf::Time & deltaTime)
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

void Player::MoveArrows(const sf::Time & deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		GoUp(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		GoDown(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		GoLeft(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
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
	switch (playerState)
	{
	case stand:
		sprite.setScale(4.f, 4.f);
		break;
	case movingLeft:
		sprite.setScale(-4.f, 4.f);
		break;
	case movingRight:
		sprite.setScale(4.f, 4.f);
		break;
	}
}

void Player::UpdateCollisionBox()									//zastanowic sie
{
	collisionBox.left = position.x - 1;
	collisionBox.top = position.y - 1;
}
