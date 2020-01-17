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
	Map map;
	
	//-------------- tymczasowe ---------------------------
	sf::Texture texture1;
	if (!texture1.loadFromFile("res/img/character1.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
	}
	//-------------- tymczasowe ---------------------------
	sf::Texture texture2;
	if (!texture2.loadFromFile("res/img/character2.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
	}
	//-------------- tymczasowe ---------------------------
	sf::Texture solid_texture;
	if (!solid_texture.loadFromFile("res/img/character1.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
	}
	//------------------------------------------------------

	player1.LoadTexture(texture1);
	player2.LoadTexture(texture2);

	//----------- kafelki na mapie -----------------------------
	/*std::vector<std::vector<int>> tiles = 
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
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
	};*/
		
	for (int y = 0; y < 11; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			SolidWall tile;
			tile.LoadTexture(solid_texture);
			//tile.Update(time);
			tile.SetPosition(sf::Vector2f(x * 40, y * 40));
			tile.Draw(window);
		}
	}
	//-------------------------------------------------------------

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

		player1.Update(time);
		player2.Update(time);

		Draw();

		//std::cout << "x = " << player.GetPosition().x << "   y = " << player.GetPosition().y << std::endl;

		window.display();

	}
}
