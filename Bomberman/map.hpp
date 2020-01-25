#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "block.hpp"

class Map
{
	sf::Texture textureSet;

	unsigned int gameMap[11][15] = 
	{
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 2, 1, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2 },
		{ 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 1, 2, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2 },
		{ 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2 },
		{ 2, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 2 },
		{ 2, 0, 2, 0, 2, 0, 2, 1, 2, 0, 2, 0, 2, 0, 2 },
		{ 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 }
	};

public:
	int tileSize;

	Block * blocks[11][15];

	Map();

	void LoadTiles();

	void Update(const sf::Time deltaTime);

	void Draw(sf::RenderWindow & window);

};