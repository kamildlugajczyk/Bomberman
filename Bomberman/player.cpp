#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "player.hpp"
#include "bomb.hpp"
#include "map.hpp"



Player::Player(bool up, bool down, bool right, bool left)
	: canGoUp(up), canGoDown(down), canGoRight(right), canGoLeft(left), timeSinceBomb(0.f), bombCooldown(2.f)
{
	defaultVelocity = { 200.f, 200.f };
	velocity = defaultVelocity;

	collisionBox.width = 50;
	collisionBox.height = 50;

	playerState = stand;

	sprite.setOrigin(16, 24);
}

void Player::MoveWSAD(const sf::Time & deltaTime, Map & map)
{
	timeSinceBomb -= deltaTime.asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		GoUp(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		GoDown(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		GoLeft(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		GoRight(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timeSinceBomb <= 0)
	{
		timeSinceBomb = bombCooldown;

		Bomb * bomb = new Bomb();
		bomb->LoadTexture(bomb->bombTexture);

		sf::Vector2f bombLocation = this->GetPosition();									// robi zeby bomba  
		bombLocation.x = ((int)bombLocation.x / 64) * 64;									// pojawila sie dokladnie
		bombLocation.y = ((int)bombLocation.y / 64) * 64;									// w kratce a nie np w polowie

		bomb->SetPosition(bombLocation);

		map.blocks[(int)(this->position.y) / 64][(int)(this->position.x) / 64] = bomb;
	}
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
		sprite.setScale(3.3f, 3.3f);
		break;
	case movingLeft:
		sprite.setScale(-3.3f, 3.3f);
		break;
	case movingRight:
		sprite.setScale(3.3f, 3.3f);
		break;
	}
}

void Player::UpdateCollisionBox()									//zastanowic sie
{
	collisionBox.left = position.x - 1;
	collisionBox.top = position.y - 1;
}

//void Player::PlaceBomb(const sf::Time deltaTime)
//{
//	Bomb * bomb = new Bomb();
//
//	//gameMap[1][1] = 1;
//
//	bomb->SetPosition(this->position);
//
//	bomb->Update(deltaTime);
//}
