#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "player.hpp"
#include "bomb.hpp"
#include "map.hpp"
#include "enum.hpp"

#include "windows.h"


Player::Player(bool up, bool down, bool right, bool left)
	: canGoUp(up), canGoDown(down), canGoRight(right), canGoLeft(left), timeSinceBomb(0.f), bombCooldown(2.f)
{
	defaultVelocity = { 200.f, 200.f };
	velocity = defaultVelocity;

	collisionBox.width = 48;
	collisionBox.height = 48;

	playerState = stand;

	sprite.setOrigin(collisionBox.width / 2, collisionBox.height / 2);
	//sprite.setOrigin(16, 16);
}

void Player::MoveWSAD(const sf::Time & deltaTime, Map & map)
{
	timeSinceBomb -= deltaTime.asSeconds();

	CheckForCollisions(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		GoUp(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		GoDown(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		GoLeft(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		GoRight(deltaTime, map);

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
		map.blocks[(int)(this->position.y) / 64][(int)(this->position.x) / 64]->type = bombBlock;
	}
}

void Player::MoveArrows(const sf::Time & deltaTime, Map & map)
{
	timeSinceBomb -= deltaTime.asSeconds();

	CheckForCollisions(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		GoUp(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		GoDown(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		GoLeft(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		GoRight(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && timeSinceBomb <= 0)
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

void Player::GoUp(const sf::Time & deltaTime, Map & map)
{
	if (canGoUp)
	{
		position.y -= int(velocity.y * deltaTime.asSeconds());
		playerState = movingUp;
	}
}

void Player::GoDown(const sf::Time & deltaTime, Map & map)
{
	if (canGoDown)
	{
		position.y += int(velocity.y * deltaTime.asSeconds());
		playerState = movingDown;
	}
}

void Player::GoLeft(const sf::Time & deltaTime, Map & map)
{
	if (canGoLeft)
	{
		position.x -= int(velocity.x * deltaTime.asSeconds());
		playerState = movingLeft;
	}
}

void Player::GoRight(const sf::Time & deltaTime, Map & map)

{
	if (canGoRight)
	{
		position.x += int(velocity.x * deltaTime.asSeconds());
		playerState = movingRight;
	}
}

void Player::Update(const sf::Time deltaTime)
{
	UpdateSprite();

	UpdateCollisionBox();

	sprite.setPosition(position);
}

void Player::UpdateSprite()
{
	switch (playerState)
	{
	case stand:
		sprite.setScale(1.f, 1.f);
		break;
	case movingLeft:
		sprite.setScale(-1.f, 1.f);
		break;
	case movingRight:
		sprite.setScale(1.f, 1.f);
		break;
	}
}

void Player::UpdateCollisionBox()									//zastanowic sie
{
	collisionBox.left = position.x;
	collisionBox.top = position.y;
}

void Player::CheckForCollisions(const sf::Time & deltaTime, Map & map)
{
	float leftPlayerEdge = this->GetCollisionBox().left - collisionBox.width / 2;
	//float rightPlayerEdge = this->GetCollisionBox().left + this->GetCollisionBox().width + 24;
	float rightPlayerEdge = this->GetCollisionBox().left + collisionBox.width / 2;
	float topPlayerEdge = this->GetCollisionBox().top - collisionBox.height / 2;
	//float bottomPlayerEdge = this->GetCollisionBox().top + this->GetCollisionBox().height + 24;
	float bottomPlayerEdge = this->GetCollisionBox().top + collisionBox.height / 2;
	
	/*std::cout << "\n\n\nTyp: " << map.blocks[(int)(this->GetPosition().y / 64)][(int)((this->GetPosition().x) / 64)]->type << std::endl;
	std::cout << "Pozycja y: " << (int)(this->GetPosition().y / 64) << std::endl;
	std::cout << "Pozycja x: " << (int)(this->GetPosition().x / 64) << std::endl;
	std::cout << "CollisionBox.left: " << map.blocks[(int)(this->GetPosition().y / 64)][(int)((this->GetPosition().x) / 64)]->GetCollisionBox().left << std::endl;
	std::cout << "CollisionBox.top: " << map.blocks[(int)(this->GetPosition().y / 64)][(int)((this->GetPosition().x) / 64)]->GetCollisionBox().top << std::endl;
	std::cout << "CollisionBox.width: " << map.blocks[(int)(this->GetPosition().y / 64)][(int)((this->GetPosition().x) / 64)]->GetCollisionBox().width << std::endl;
	std::cout << "CollisionBox.height: " << map.blocks[(int)(this->GetPosition().y / 64)][(int)((this->GetPosition().x) / 64)]->GetCollisionBox().height << std::endl;
	std::cout << "\nGracz.left: " << leftPlayerEdge << std::endl;
	std::cout << "Gracz.top: " << topPlayerEdge << std::endl;
	std::cout << "Gracz.right: " << rightPlayerEdge << std::endl;
	std::cout << "Gracz.bottom: " << bottomPlayerEdge << std::endl;*/

	sf::FloatRect player(sf::Vector2f(leftPlayerEdge / 64, topPlayerEdge / 64), sf::Vector2f(rightPlayerEdge / 64, bottomPlayerEdge / 64));

	if (map.blocks[(int)(this->GetPosition().y / 64)][(int)((this->GetPosition().x) / 64)]->type == explosionBlock
		&& map.blocks[(int)(this->GetPosition().y / 64)][(int)((this->GetPosition().x) / 64)]->GetCollisionBox().intersects(player))
	{
		std::cout << " YOU ARE DEAD! \n";
		system("cls");
	}


	//kolizje z lewej
	if (map.blocks[(int)(topPlayerEdge / 64)][(int)((leftPlayerEdge - 1) / 64)]->type == solidBlock
		|| map.blocks[(int)(topPlayerEdge / 64)][(int)((leftPlayerEdge - 1) / 64)]->type == breakableBlock
		|| map.blocks[(int)(bottomPlayerEdge / 64)][(int)((leftPlayerEdge - 1) / 64)]->type == solidBlock
		|| map.blocks[(int)(bottomPlayerEdge / 64)][(int)((leftPlayerEdge - 1) / 64)]->type == breakableBlock)
	{
		this->ForbidGoingLeft();
		position.x += 1;
	}
	else
		this->AllowGoingLeft();
	
	// kolizje z prawej
	if (map.blocks[(int)(topPlayerEdge / 64)][(int)((rightPlayerEdge + 1) / 64)]->type == solidBlock
		|| map.blocks[(int)(topPlayerEdge / 64)][(int)((rightPlayerEdge + 1) / 64)]->type == breakableBlock
		|| map.blocks[(int)(bottomPlayerEdge / 64)][(int)((rightPlayerEdge + 1) / 64)]->type == solidBlock
		|| map.blocks[(int)(bottomPlayerEdge / 64)][(int)((rightPlayerEdge + 1) / 64)]->type == breakableBlock)
	{
		this->ForbidGoingRight();
		position.x -= 1;
	}
	else
		this->AllowGoingRight();

	// kolizje z gora
	if (map.blocks[(int)((topPlayerEdge - 1) / 64)][(int)(leftPlayerEdge / 64)]->type == solidBlock
		|| map.blocks[(int)((topPlayerEdge - 1) / 64)][(int)(leftPlayerEdge / 64)]->type == breakableBlock
		|| map.blocks[(int)((topPlayerEdge - 1) / 64)][(int)(rightPlayerEdge / 64)]->type == solidBlock
		|| map.blocks[(int)((topPlayerEdge - 1) / 64)][(int)(rightPlayerEdge / 64)]->type == breakableBlock)
	{
		this->ForbidGoingUp();
		position.y += 1;
	}
	else
		this->AllowGoingUp();

	// kolizje z dolem
	if (map.blocks[(int)((bottomPlayerEdge + 1) / 64)][(int)(leftPlayerEdge / 64)]->type == solidBlock
		|| map.blocks[(int)((bottomPlayerEdge + 1) / 64)][(int)(leftPlayerEdge / 64)]->type == breakableBlock
		|| map.blocks[(int)((bottomPlayerEdge + 1) / 64)][(int)(rightPlayerEdge / 64)]->type == solidBlock
		|| map.blocks[(int)((bottomPlayerEdge + 1) / 64)][(int)(rightPlayerEdge / 64)]->type == breakableBlock)
	{
		this->ForbidGoingDown();
		position.y -= 1;
	}
	else
		this->AllowGoingDown();
}



