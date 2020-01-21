#include <iostream>
#include <SFML/Graphics.hpp>

#include "bomb.hpp"

Bomb::Bomb()
{
	if (!bombTexture.loadFromFile("res/img/bomb.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
	}
}

void Bomb::Update(const sf::Time deltaTime)
{
	sprite.setPosition(position);
}
