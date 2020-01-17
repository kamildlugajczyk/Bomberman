#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "block.hpp"

class Bomb : public Block
{


public:
	void Update(const sf::Time deltaTime);
};