#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "block.hpp"

class Map
{
	sf::Texture textureSet;
	int tileSize;

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
	Block * blocks[11][15];

	Map();

	void LoadTiles();

	void LoadTexture(const sf::Texture & texture);

	void Update(const sf::Time deltaTime);

	void Draw(sf::RenderWindow & window);
};