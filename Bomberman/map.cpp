#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "map.hpp"

Map::Map()
{
	gameMap = {};
}

void Map::Draw(sf::RenderWindow & window)
{
	for (auto y = 0u; y < 15; y++)
	{
		for (auto x = 0u; y < 20; x++)
		{
			window.draw(tile);
		}
	}
}
