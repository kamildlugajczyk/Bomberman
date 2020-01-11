#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


class Map
{
	sf::Sprite tile;
	std::vector<std::vector<unsigned char>> gameMap;

public:
	Map();

	void Draw(sf::RenderWindow & window);
};