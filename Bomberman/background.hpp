#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "wall.hpp"

class Background : public Wall
{

public:
	sf::Texture backgroundTexture;

	Background();
};