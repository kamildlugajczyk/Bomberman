#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "wall.hpp"

class BreakableWall : public Wall
{

public:
	sf::Texture breakable_wall;

	BreakableWall();
};