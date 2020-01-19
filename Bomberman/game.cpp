#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "player.hpp"
#include "map.hpp"
#include "solid_wall.hpp"
#include "breakable_wall.hpp"

Game::Game()
{
	windowSize.x = 800;
	windowSize.y = 600;
	window.create(sf::VideoMode(windowSize.x, windowSize.y), "Bomberman");

	window.setFramerateLimit(60);

	player1.SetPosition(sf::Vector2f( 200, 200));
	player1.SetPosition(sf::Vector2f( 600, 200));

	isOver = false;
}

//void Game::LoadResoures()
//{
//	// todo : load map
//
//	sf::Texture texture_p1;
//	if (!texture_p1.loadFromFile("res/img/character1.png"))
//	{
//		std::cout << "Load failed! " << std::endl;
//		getchar();
//	}
//
//	sf::Texture texture_p2;
//	if (!texture_p2.loadFromFile("res/img/character2.png"))
//	{
//		std::cout << "Load failed! " << std::endl;
//		getchar();
//	}
//
//	player1.LoadTexture(texture_p1);
//	player2.LoadTexture(texture_p2);
//}

void Game::Draw()
{
	//map.Draw(window);
	player1.Draw(window);
	player2.Draw(window);
}

void Game::play()
{
	sf::Clock clock;
	sf::Time time;
	
	////-------------- gracz 1 ---------------------------
	sf::Texture texture_p1;
	if (!texture_p1.loadFromFile("res/img/character1.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
	}
	//-------------- gracz 2 ---------------------------
	sf::Texture texture_p2;
	if (!texture_p2.loadFromFile("res/img/character2.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
	}
	//-------------- mapa ---------------------------
	sf::Texture solid_texture;
	if (!solid_texture.loadFromFile("res/img/SolidBlock.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
	}
	//----------------------------------------------

	player1.LoadTexture(texture_p1);
	player2.LoadTexture(texture_p2);
	//map.LoadTexture(solid_texture);
	//map.LoadTiles(solid_texture);
	//map.Update(solid_texture);

	//-------------------------------------------------------------
	//LoadResoures();

	//----------------
	/*BreakableWall * breakable = new BreakableWall;
	breakable->LoadTexture(solid_texture);
	breakable->SetPosition(sf::Vector2f (100, 100));
	breakable->Draw(window);*/

	//------------------------------------------------------GIGA TEST-------------------------------------------------------
	
	unsigned int gameMap[11][15] =
	{
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 }
	};

	Block blocks[11][15];

	for (int w = 0; w < 11; w++)
	{
		for (int k = 0; k < 15; k++)
		{
			if (gameMap[w][k] == 1)									// 0 nic , 1 do zniszczenia, 2 nie do zniszczenia
			{
				BreakableWall * breakable = new BreakableWall;
				blocks[w][k] = *breakable;
				//blocks[w][k].SetPosition(sf::Vector2f(w * 64, k * 64));
				blocks[w][k].LoadTexture(solid_texture);

				blocks[w][k].Update(time);
				
			}
			else if (gameMap[w][k] == 2)
			{
				SolidWall * solid = new SolidWall;
				blocks[w][k] = *solid;
				blocks[w][k].SetPosition(sf::Vector2f(w * 64, k * 64));
				blocks[w][k].LoadTexture(solid_texture);
				blocks[w][k].Update(time);

			}
			else if (gameMap[w][k] == 0)
			{
				SolidWall * solid = new SolidWall;
				blocks[w][k] = *solid;
				blocks[w][k].SetPosition(sf::Vector2f(w * 64, k * 64));
				//blocks[w][k].LoadTexture(solid_texture);

				blocks[w][k].Update(time);

			}
		}
	}

	//------------------------------------------------------KONIEC GIGA TESTU--------------------------------------------------

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();
		}

		window.clear(sf::Color::Black);
		time = clock.restart();

		//map.LoadTiles(solid_texture);

		player1.MoveWSAD(time);
		player2.MoveArrows(time);

		
		player1.Update(time);
		player2.Update(time);

		//map.Draw(window);

		Draw();
		for (int w = 0; w < 11; w++)
		{
			for (int k = 0; k < 15; k++)
			{
				blocks[w][k].Draw(window);
			}
		}
		
		window.display();

	}
}
