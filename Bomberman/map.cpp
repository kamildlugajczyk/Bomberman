#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "map.hpp"
#include "solid_wall.hpp"
#include "breakable_wall.hpp"
#include "background.hpp"
#include "bomb.hpp"
#include "explosion.hpp"

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
				Background * background = new Background;
				blocks[w][k] = background;
				blocks[w][k]->SetPosition(sf::Vector2f(k * 64, w * 64));
				blocks[w][k]->LoadTexture(background->backgroundTexture);
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
		{
			blocks[w][k]->Update(deltaTime);

			if (blocks[w][k]->IsDestroyed())
			{
				delete blocks[w][k];													// usuwam bombe

				Explosion * explosion1 = new Explosion();								// w tym miejscu tworze blok tla
				blocks[w][k] = explosion1;												// .
				blocks[w][k]->SetPosition(sf::Vector2f(k * 64, w * 64));				// .
				blocks[w][k]->LoadTexture(explosion1->explosionTexture);

				if (blocks[w - 1][k])
				{
					Explosion * explosion4 = new Explosion();								// w tym miejscu tworze blok tla
					blocks[w - 1][k] = explosion4;												// .
					blocks[w - 1][k]->SetPosition(sf::Vector2f(k * 64, (w - 1) * 64));				// .
					blocks[w - 1][k]->LoadTexture(explosion4->explosionTexture);
				}
				if (blocks[w + 1][k])
				{
					Explosion * explosion5 = new Explosion();								// w tym miejscu tworze blok tla
					blocks[w + 1][k] = explosion5;												// .
					blocks[w + 1][k]->SetPosition(sf::Vector2f(k * 64, (w + 1) * 64));				// .
					blocks[w + 1][k]->LoadTexture(explosion5->explosionTexture);
				}
				if (blocks[w][k - 1])
				{
					Explosion * explosion2 = new Explosion();								// w tym miejscu tworze blok tla
					blocks[w][k - 1] = explosion2;												// .
					blocks[w][k - 1]->SetPosition(sf::Vector2f((k - 1) * 64, w * 64));				// .
					blocks[w][k - 1]->LoadTexture(explosion2->explosionTexture);
				}
				if (blocks[w][k + 1])
				{
					Explosion * explosion3 = new Explosion();								// w tym miejscu tworze blok tla
					blocks[w][k + 1] = explosion3;												// .
					blocks[w][k + 1]->SetPosition(sf::Vector2f((k + 1) * 64, w * 64));				// .
					blocks[w][k + 1]->LoadTexture(explosion3->explosionTexture);
				}
			}

			if (blocks[w][k]->IsExploded())
			{
				delete blocks[w][k];

				Background * background = new Background;								// w tym miejscu tworze blok tla
				blocks[w][k] = background;												// .
				blocks[w][k]->SetPosition(sf::Vector2f(k * 64, w * 64));				// .
				blocks[w][k]->LoadTexture(background->backgroundTexture);				// .

			}
		}
}

void Map::Draw(sf::RenderWindow & window)
{
	for (int w = 0; w < 11; w++)			
		for (int k = 0; k < 15; k++)
			blocks[w][k]->Draw(window);
}
