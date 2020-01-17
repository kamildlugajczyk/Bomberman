#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "wall.hpp"

class SolidWall : public Wall
{
	int niewiem;
public:
	SolidWall();

	void Update(const sf::Time deltaTime);
};