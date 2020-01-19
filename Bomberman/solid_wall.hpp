#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "wall.hpp"

class SolidWall : public Wall
{
	/*sf::Texture solid_texture;*/

public:
	//SolidWall();

	void Update(const sf::Time deltaTime);
};