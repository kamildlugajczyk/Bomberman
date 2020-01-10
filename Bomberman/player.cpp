#include <iostream>
#include <SFML/Graphics.hpp>

#include "player.hpp"

void Player::move(sf::Time & dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		goUp(dt);

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		goDown(dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		goLeft(dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		goRight(dt);*/
}

void Player::goUp(const sf::Time & dt)
{
	//sprite.move(sf::Vector2f(5.f, 5.f))
	/*if (canGoUp)
	{
		position.y += defaultVelocity * dt.asSeconds;
	}*/
}

//void Player::goDown(sf::Time & dt)
//{
//	if (canGoDown)
//	{
//		position.y -= defaultVelocity * dt.asSeconds;
//	}
//}
//
//void Player::goLeft(sf::Time & dt)
//{
//	if (canGoLeft)
//	{
//		position.x -= defaultVelocity * dt.asSeconds;
//	}
//}
//
//void Player::goRight(sf::Time & dt)
//{
//	if (canGoRight)
//	{
//		position.x += defaultVelocity * dt.asSeconds;
//	}
//}

