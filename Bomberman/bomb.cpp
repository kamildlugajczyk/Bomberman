#include <iostream>
#include <SFML/Graphics.hpp>

#include "bomb.hpp"
#include "explosion.hpp"

Bomb::Bomb() : explodeTime(3.f)
{
	if (!bombTexture.loadFromFile("res/img/bomb.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
	}

	sprite.setOrigin(-10, -10);
}

void Bomb::Update(const sf::Time deltaTime)
{
	sprite.setPosition(position);

	explodeTime -= deltaTime.asSeconds();
	if (explodeTime <= 0)
	{
		this->Destroy();

		/*Explosion * explosion1 = new Explosion();
		explosion1->SetPosition(this->position);
		explosion1->LoadTexture(explosion1->explosionTexture);
		explosion1->Update(deltaTime);*/
	}
}

