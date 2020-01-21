#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "map.hpp"
#include "solid_wall.hpp"
#include "breakable_wall.hpp"


Map::Map() : tileSize(64) {};

void Map::LoadTiles()
{
	for (int w = 0; w < 11; w++)
	{
		for (int k = 0; k < 15; k++)
		{
			if (gameMap[w][k] == 1)									// 0 nic , 1 do zniszczenia, 2 nie do zniszczenia
			{
				BreakableWall * breakable = new BreakableWall;
				blocks[w][k] = breakable;
				blocks[w][k]->SetPosition(sf::Vector2f(k * 64, w * 64));
				blocks[w][k]->LoadTexture(breakable->breakable_wall);
			}
			else if (gameMap[w][k] == 2)
			{
				SolidWall * solid = new SolidWall;
				blocks[w][k] = solid;
				blocks[w][k]->SetPosition(sf::Vector2f(k * 64, w * 64));
				blocks[w][k]->LoadTexture(solid->solid_texture);
			}
			else if (gameMap[w][k] == 0)
			{
				SolidWall * solid = new SolidWall;
				blocks[w][k] = solid;
				blocks[w][k]->SetPosition(sf::Vector2f(k * 64, w * 64));
				//blocks[w][k]->LoadTexture(solid_texture);
			}
		}
	}
}

//void Map::LoadTexture(const sf::Texture & texture)
//{
//	textureSet = texture;
//}

void Map::Update(const sf::Time deltaTime)
{
	for (int w = 0; w < 11; w++)
		for (int k = 0; k < 15; k++)
			blocks[w][k]->Update(deltaTime);
}

void Map::Draw(sf::RenderWindow & window)
{
	for (int w = 0; w < 11; w++)			
		for (int k = 0; k < 15; k++)
			blocks[w][k]->Draw(window);
}
