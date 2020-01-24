#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "block.hpp"

class Bomb : public Block
{
	float explodeTime;

public:
	sf::Texture bombTexture;

	Bomb();

	void Update (const sf::Time deltaTime) override;
};