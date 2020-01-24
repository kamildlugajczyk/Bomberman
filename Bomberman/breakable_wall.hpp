#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "wall.hpp"
#include "enum.hpp"

class BreakableWall : public Wall
{
	//int type = breakableBlock;
public:
	sf::Texture breakable_wall;

	BreakableWall();
};