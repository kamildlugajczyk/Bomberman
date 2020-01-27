#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "wall.hpp"

class SolidWall : public Wall
{
	int type = solidBlock;
	sf::Texture solid_texture;
public:

	SolidWall();

	virtual void SetUp() override;
};