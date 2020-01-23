#include <iostream>
#include <SFML/Graphics.hpp>

#include "explosion.hpp"

Explosion::Explosion() : flameTime(1.f)
{
	if (!explosionTexture.loadFromFile("res/img/flame.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
	}

	sprite.setOrigin(-10, -10);
}

void Explosion::Update(const sf::Time deltaTime)
{
	sprite.setPosition(position);

	flameTime -= deltaTime.asSeconds();
	if (flameTime <= 0)
	{
		this->Explode();
	}
}