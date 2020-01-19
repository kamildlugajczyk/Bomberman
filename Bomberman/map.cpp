#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "map.hpp"
#include "solid_wall.hpp"
#include "breakable_wall.hpp"

Map::Map() : tileSize(64) {};

void Map::LoadTiles(sf::Texture solid_texture)
{
	for (int w = 0; w < 11; w++)
	{
		for (int k = 0; k < 15; k++)
		{				
			//if (gameMap[w][k] == 1)									// 0 nic , 1 do zniszczenia, 2 nie do zniszczenia
			//{
			//	BreakableWall * breakable = new BreakableWall;
			//	blocks[w][k] = breakable;
			//	blocks[w][k]->SetPosition(sf::Vector2f(w * 40, k * 40));
			//}
			/*else*/ if (gameMap[w][k] == 2)
			{
				SolidWall * solid = new SolidWall;
				blocks[w][k] = solid;
				blocks[w][k]->LoadTexture(solid_texture);
				blocks[w][k]->SetPosition(sf::Vector2f(w * 40, k * 40));
			}
			/*else if (gameMap[w][k] == 0)
			{
				SolidWall * solid = new SolidWall;
				blocks[w][k] = solid;
				blocks[w][k]->SetPosition(sf::Vector2f(w * 40, k * 40));
			}*/
		}
	}

	/*for (int w = 0; w < 11; w++)
	{
		for (int k = 0; k < 15; k++)
		{
			std::cout << "(" << blocks[w][k].GetPosition().x << ", " << blocks[w][k].GetPosition().y << ") ";
		}
		std::cout << std::endl;
	}*/
}

void Map::LoadTexture(const sf::Texture & texture)
{
	textureSet = texture;
}

void Map::Update(sf::Texture solid_texture)
{
	

	for (int w = 0; w < 11; w++)
	{
		for (int k = 0; k < 15; k++)
		{
			/*blocks[w][k]->SetPosition(sf::Vector2f(w * 40, k * 40));*/
			//spriteSet[y][x].setScale(1, 1);								moze sie przydac
			//blocks[y][x].LoadTexture(textureSet);
			
			/*blocks[w][k]->LoadTexture(solid_texture);*/
			//spriteSet[y][x].setTextureRect(sf::IntRect(0, 0, 16, 16));
		}
	}

	for (int w = 0; w < 11; w++)
	{
		for (int k = 0; k < 15; k++)
		{
			//std::vector<std::vector<Block>> blocks;
			std::cout << "(" << blocks[w][k]->GetPosition().x << ", " << blocks[w][k]->GetPosition().y << ") ";
		}
		std::cout << std::endl;
	}
}

void Map::Draw(sf::RenderWindow & window)
{
	for (int w = 0; w < 11; w++)
	{
		for (int k = 0; k < 15; k++)
		{
			blocks[w][k]->Draw(window);
		}
	}
}
