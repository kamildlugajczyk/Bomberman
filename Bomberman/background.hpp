#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "wall.hpp"

class Background : public Wall
{
	sf::Texture backgroundTexture;

public:

	Background();

	virtual void SetUp() override;
};