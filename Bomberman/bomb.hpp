#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "block.hpp"

class Bomb : public Block
{
	int timeSinceLast;

public:
	sf::Texture bombTexture;

	Bomb();

	void Update(const sf::Time deltaTime);
};