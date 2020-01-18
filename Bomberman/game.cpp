#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "player.hpp"
#include "map.hpp"
#include "solid_wall.hpp"

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
	map.Draw(window);
	player1.Draw(window);
	player2.Draw(window);
}

void Game::play()
{
	sf::Clock clock;
	sf::Time time;
	Map map;
	
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
	map.LoadTexture(solid_texture);

	//for (int y = 0; y < 11; y++)
	//{
	//	for (int x = 0; x < 15; x++)
	//	{
	//		SolidWall tile;
	//		tile.LoadTexture(solid_texture);
	//		//tile.Update(time);
	//		tile.SetPosition(sf::Vector2f(x * 40, y * 40));
	//		tile.Draw(window);
	//	}
	//}
	//-------------------------------------------------------------
	//LoadResoures();

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

		player1.MoveWSAD(time);
		player2.MoveArrows(time);

		//map.Update();
		player1.Update(time);
		player2.Update(time);


		Draw();

		//std::cout << "x = " << player.GetPosition().x << "   y = " << player.GetPosition().y << std::endl;

		window.display();

	}
}
