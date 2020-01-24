#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "wall.hpp"

class SolidWall : public Wall
{
	//int type = solidBlock;
public:


	sf::Texture solid_texture;

	SolidWall();
};