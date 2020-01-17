#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "map.hpp"

Map::Map() : tileSize(64) {};

void Map::loadTexture(const sf::Texture & texture)
{
	textureSet = texture;
}

void Map::Update()
{
	for (int y = 0; y < 15; y++)
	{
		for (int x = 0; y < 20; x++)
		{
			spriteSet[y][x].setPosition(x * 40, y * 40);
			//spriteSet[y][x].setScale(1, 1);								moze sie przydac
			spriteSet[y][x].setTexture(textureSet);
			//spriteSet[y][x].setTextureRect(sf::IntRect(0, 0, 16, 16));
		}
	}
}


void Map::Draw(sf::RenderWindow & window)
{
	/*for (auto const & row : spriteSet)
	{
		for (auto const & cell : row)
		{
			window.draw(cell);
		}
	}*/
	//
	for (int y = 0; y < 15; y++)
	{
		for (int x = 0; y < 20; x++)
		{
			window.draw(spriteSet[x][y]);
		}
	}
}
