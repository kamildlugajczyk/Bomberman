#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "graphic_object.hpp"

class Block : public GraphicObject
{
	//sf::Sprite block_sprite;

	bool isCollideable; 
	bool isInjurious; 

public:

	//virtual void Update(const sf::Time deltaTime);                   // wirtualna ?
};