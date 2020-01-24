#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "player.hpp"
#include "bomb.hpp"
#include "map.hpp"
#include "enum.hpp"



Player::Player(bool up, bool down, bool right, bool left)
	: canGoUp(up), canGoDown(down), canGoRight(right), canGoLeft(left), timeSinceBomb(0.f), bombCooldown(2.f)
{
	defaultVelocity = { 200.f, 200.f };
	velocity = defaultVelocity;

	/*collisionBox.width = 50;
	collisionBox.height = 50;*/

	/*sf::FloatRect helpCollider(sf::Vector2f(this->GetPosition().x, this->GetPosition().y), sf::Vector2f(30, 30));
	collider = helpCollider;*/

	playerState = stand;

	//sprite.setOrigin(28, 22);
	//sprite.setOrigin(16, 16);
}

void Player::MoveWSAD(const sf::Time & deltaTime, Map & map)
{
	timeSinceBomb -= deltaTime.asSeconds();

	

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
	}
}

void Player::MoveArrows(const sf::Time & deltaTime, Map & map)
{
	timeSinceBomb -= deltaTime.asSeconds();


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
		position.y -= velocity.y * deltaTime.asSeconds();
		playerState = movingUp;

		/*if(map.blocks[(int)(this->position.y) / 64][(int)(this->position.x) / 64]->blockCollider.intersects(collider))*/


		//CheckForCollisions(deltaTime, map);

		if (this->CheckForCollisions(deltaTime, map))
		{
			std::cout << " Kolizja z gory \n";
			position.y += velocity.y * deltaTime.asSeconds();

		}
	}
}

void Player::GoDown(const sf::Time & deltaTime, Map & map)
{
	if (canGoDown)
	{
		position.y += velocity.y * deltaTime.asSeconds();
		playerState = movingDown;

		//sf::Vector2f helpPosition = position;

		//CheckForCollisions(deltaTime, map);

		if (this->CheckForCollisions(deltaTime, map))
		{
			std::cout << " Kolizja z dolu \n";
			position.y -= velocity.y * deltaTime.asSeconds();
			//position = helpPosition;

		}
	}
}

void Player::GoLeft(const sf::Time & deltaTime, Map & map)
{
	if (canGoLeft)
	{
		position.x -= velocity.x * deltaTime.asSeconds();
		playerState = movingLeft;

		//sf::Vector2f helpPosition = position;
		//
		//CheckForCollisions(deltaTime, map);

		if (this->CheckForCollisions(deltaTime, map))
		{
			std::cout << " Kolizja z lewej \n";

			position.x += velocity.x * deltaTime.asSeconds();
			//this->SetPosition(sf::Vector2f(position.x + velocity.x * deltaTime.asSeconds(), position.y));
			//position = helpPosition;

		}
	}
}

void Player::GoRight(const sf::Time & deltaTime, Map & map)

{
	if (canGoRight)
	{
		position.x += velocity.x * deltaTime.asSeconds();
		playerState = movingRight;

		//sf::Vector2f helpPosition = position;
		//CheckForCollisions(deltaTime, map);

		if (this->CheckForCollisions(deltaTime, map))
		{
			//std::cout << " Kolizja z prawej \n";
			position.x -= velocity.x * deltaTime.asSeconds();
			//this->SetPosition(sf::Vector2f(position.x - velocity.x * deltaTime.asSeconds(), position.y));

			//position = helpPosition;
		}
		//this->SetPosition(position);
	}
}

void Player::Update(const sf::Time deltaTime)
{
	//UpdateSprite();

	sf::FloatRect helpCollider(sf::Vector2f(this->GetPosition().y, this->GetPosition().x), sf::Vector2f(32, 32));
	//sf::FloatRect helpCollider(sf::Vector2f(this->GetPosition().y - 16 , this->GetPosition().x - 16), sf::Vector2f(32, 32));

	collider = helpCollider;

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
	collisionBox.left = position.x - 1;
	collisionBox.top = position.y - 1;
}

bool Player::CheckForCollisions(const sf::Time & deltaTime, Map & map)
{
	for (int w = 0; w < 11; w++)
		for (int k = 0; k < 15; k++)
		{
			if ((map.blocks[w][k]->type != backgroundBlock) && (map.blocks[w][k]->blockCollider.intersects(collider)))
			{
				std::cout << map.blocks[w][k] << " intersects on " << w << ", " << k << std::endl;
				return true;
			}
		}
	return false;
}

//bool Player::CheckForCollisions(const sf::Time & deltaTime, Map & map)
//{
//	for (int w = 0; w < 11; w++)
//		for (int k = 0; k < 15; k++)
//		{
//			nextPosition = collider;
//			nextPosition.left +=  velocity.x * deltaTime.asSeconds();
//			nextPosition.top +=  velocity.y * deltaTime.asSeconds();
//
//			if ((map.blocks[w][k]->type != backgroundBlock) && (map.blocks[w][k]->blockCollider.intersects(nextPosition)))
//				return true;
//		}
//	return false;
//}


//bool Player::CheckForCollisions(const sf::Time & deltaTime, Map & map)
//{
//	for (int w = 1; w < 10; w++)
//		for (int k = 1; k < 14; k++)
//		{
//			if (map.blocks[(int)(this->position.y) / 64][(int)(this->position.x) / 64]->blockCollider.intersects(collider))
//
//
//			nextPosition = collider;
//			nextPosition.left += velocity.x * deltaTime.asSeconds();
//			nextPosition.top += velocity.y * deltaTime.asSeconds();
//
//			if ((map.blocks[w][k]->type != backgroundBlock) && (map.blocks[w][k]->blockCollider.intersects(nextPosition)))
//				return true;
//		}
//	return false;
//}

//bool Player::CheckForCollisions(Map & map)
//{
//	for (int w = 0; w < 11; w++)
//		for (int k = 0; k < 15; k++)
//		{
//			if ((map.blocks[w][k]->type != backgroundBlock) && (map.blocks[w][k]->blockCollider.intersects(collider)))
//			{
//
//				return true;
//			}
//		}
//	return false;
//}

//void Player::CheckForCollisions(const sf::Time & deltaTime, Map & map)
//{
	//for (int w = 0; w < 11; w++)
	//	for (int k = 0; k < 15; k++)
	//	{
	//		nextPosition = collider;
	//		nextPosition.left +=  velocity.x * deltaTime.asSeconds();
	//		nextPosition.top +=  velocity.y * deltaTime.asSeconds();

	//		if ((map.blocks[w][k]->type != backgroundBlock) && (map.blocks[w][k]->blockCollider.intersects(nextPosition)))
	//		{
	//			// dol
	//			if (collider.left < map.blocks[w][k]->blockCollider.left
	//				&& collider.left + collider.width < map.blocks[w][k]->blockCollider.left + map.blocks[w][k]->blockCollider.width
	//				&& collider.top < map.blocks[w][k]->blockCollider.top + map.blocks[w][k]->blockCollider.height
	//				&& collider.top + collider.height > map.blocks[w][k]->blockCollider.top)
	//			{
	//				//velocity.x = 0.f;
	//				//this->SetPosition(sf::Vector2f(collider.left, map.blocks[w][k]->blockCollider.top - collider.height));
	//				//this->SetPosition(sf::Vector2f(map.blocks[w][k]->blockCollider.top - collider.height, collider.left));

	//				this->SetPosition(sf::Vector2f(map.blocks[w][k]->blockCollider.top + map.blocks[w][k]->blockCollider.height, collider.left));

	//			}

	//			//gora
	//			else if (collider.top > map.blocks[w][k]->blockCollider.top
	//				&& collider.top + collider.height > map.blocks[w][k]->blockCollider.top + map.blocks[w][k]->blockCollider.height
	//				&& collider.left < map.blocks[w][k]->blockCollider.left + map.blocks[w][k]->blockCollider.width
	//				&& collider.left + collider.width > map.blocks[w][k]->blockCollider.left)
	//			{
	//				//velocity.y = 0.f;
	//				//this->SetPosition(sf::Vector2f(collider.left, map.blocks[w][k]->blockCollider.top + map.blocks[w][k]->blockCollider.height));
	//				//this->SetPosition(sf::Vector2f(map.blocks[w][k]->blockCollider.top + map.blocks[w][k]->blockCollider.height, collider.left));

	//				this->SetPosition(sf::Vector2f(map.blocks[w][k]->blockCollider.top - collider.height, collider.left));

	//			}

	//			//prawo
	//			if (collider.left < map.blocks[w][k]->blockCollider.left
	//				&& collider.left + collider.width < map.blocks[w][k]->blockCollider.left + map.blocks[w][k]->blockCollider.width
	//				&& collider.top < map.blocks[w][k]->blockCollider.top + map.blocks[w][k]->blockCollider.height
	//				&& collider.top + collider.height > map.blocks[w][k]->blockCollider.top)
	//			{
	//				//velocity.x = 0.f;
	//				//this->SetPosition(sf::Vector2f(map.blocks[w][k]->blockCollider.left - collider.width, collider.top));
	//				this->SetPosition(sf::Vector2f(collider.top, map.blocks[w][k]->blockCollider.left - collider.width));
	//			}

	//			//lewo
	//			else if (collider.left > map.blocks[w][k]->blockCollider.left
	//				&& collider.left + collider.width > map.blocks[w][k]->blockCollider.left + map.blocks[w][k]->blockCollider.width
	//				&& collider.top < map.blocks[w][k]->blockCollider.top + map.blocks[w][k]->blockCollider.height
	//				&& collider.top + collider.height > map.blocks[w][k]->blockCollider.top)
	//			{
	//				//velocity.x = 0.f;
	//				//this->SetPosition(sf::Vector2f(map.blocks[w][k]->blockCollider.left + map.blocks[w][k]->blockCollider.width, collider.top));
	//				this->SetPosition(sf::Vector2f(collider.top, map.blocks[w][k]->blockCollider.left + map.blocks[w][k]->blockCollider.width));
	//			}
	//		}
	//	}

	/*float leftPlayerEdge = collider.left;
	float rightPlayerEdge = collider.left + collider.width;
	float topPlayerEdge = collider.top;
	float bottomPlayerEdge = collider.top + collider.height;

	if (map.blocks[(int)topPlayerEdge][(int)(leftPlayerEdge - 1)]->blockCollider.intersects() || map.blocks[bottomPlayerEdge / tileSize][(leftPlayerEdge - 1) / tileSize].getIsCollideable())
		player.forbidGoingLeft();
	else
		player.allowGoingLeft();

	if (map.blocks[topPlayerEdge / tileSize][(rightPlayerEdge + 1) / tileSize].getIsCollideable() || map.blocks[bottomPlayerEdge / tileSize][(rightPlayerEdge + 1) / tileSize].getIsCollideable())
		player.forbidGoingRight();
	else
		player.allowGoingRight();

	if (map.blocks[(topPlayerEdge - 1) / tileSize][leftPlayerEdge / tileSize].getIsCollideable() || map.blocks[(topPlayerEdge - 1) / tileSize][rightPlayerEdge / tileSize].getIsCollideable())
		player.fall();

	if (map.blocks[(bottomPlayerEdge + 1) / tileSize][leftPlayerEdge / tileSize].getIsCollideable() || map.blocks[(bottomPlayerEdge + 1) / tileSize][rightPlayerEdge / tileSize].getIsCollideable())
		player.hitTheGround();
	else if (player.getIsOnTheGround())
		player.fall();*/
//}





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