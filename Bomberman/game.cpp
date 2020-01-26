#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "player.hpp"
#include "map.hpp"
#include "solid_wall.hpp"
#include "breakable_wall.hpp"
#include "bomb.hpp"

Game::Game()
{
	windowSize.x = 960;
	windowSize.y = 700;
	window.create(sf::VideoMode(windowSize.x, windowSize.y), "Bomberman");

	window.setFramerateLimit(60);

	player1.SetPosition(sf::Vector2f( 72, 72));
	player2.SetPosition(sf::Vector2f( 840, 580));

	isOver = false;
}

void Game::Update(const sf::Time deltaTime)
{
	map.Update(deltaTime);
	player1.Update(deltaTime);
	player2.Update(deltaTime);
}

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
	
	////-------------- gracz 1 ---------------------------
	sf::Texture texture_p1;
	if (!texture_p1.loadFromFile("res/img/character1.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
		return;
	}
	//-------------- gracz 2 ---------------------------
	sf::Texture texture_p2;
	if (!texture_p2.loadFromFile("res/img/character2.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
		return;
	}
	//--------------------------------------------------

	player1.LoadTexture(texture_p1);
	player2.LoadTexture(texture_p2);
	map.LoadTiles();

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

		player1.MoveWSAD(time, map);
		player2.MoveArrows(time, map);

		Update(time);

		Draw();

		window.display();

	}
}
