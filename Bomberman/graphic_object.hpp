#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class GraphicObject
{
protected:
	sf::Vector2f position;
	

public:
	virtual sf::Vector2f getPosition();
};