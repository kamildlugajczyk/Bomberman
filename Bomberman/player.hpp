#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "graphic_object.hpp"

class Player : public GraphicObject
{
	float velocity;


public:
	void move(sf::Time & dt);

};