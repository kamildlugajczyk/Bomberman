#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "map.hpp"
#include "solid_wall.hpp"
#include "breakable_wall.hpp"

Map::Map() : tileSize(64) {};

void Map::LoadTiles()
{
	for (int y = 0; y < 15; y++)
	{
		for (int x = 0; y < 20; x++)
		{
			switch (gameMap[x][y])						// 0 nic , 1 do zniszczenia, 2 nie do zniszczenia
			{
			case 0:

				break;
			case 1:
				Break
				break;
			case 2:

				break;
			}
		}
	}
}

void Map::LoadTexture(const sf::Texture & texture)
{
	textureSet = texture;
}

void Map::Update()
{
	for (int y = 0; y < 15; y++)
	{
		for (int x = 0; y < 11; x++)
		{
			/*SolidWall sciana;
			sciana.SetTexture()*/
			spriteSet[y][x].setPosition(x * 40, y * 40);
			//spriteSet[y][x].setScale(1, 1);								moze sie przydac
			spriteSet[y][x].setTexture(textureSet);
			//spriteSet[y][x].setTextureRect(sf::IntRect(0, 0, 16, 16));
		}
	}
}


void Map::Draw(sf::RenderWindow & window)
{
	for (int y = 0; y < 15; y++)
	{
		for (int x = 0; x < 11; x++)
		{
			window.draw(spriteSet[x][y]);
		}
	}

}
