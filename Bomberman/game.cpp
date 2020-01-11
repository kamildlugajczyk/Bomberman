#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "player.hpp"
#include "map.hpp"

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
	// tymczasowe
	sf::Texture texture1;
	if (!texture1.loadFromFile("res/img/character1.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
	}
	// tymczasowe
	sf::Texture texture2;
	if (!texture2.loadFromFile("res/img/character2.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
	}
	//--------------------------

	player1.LoadTexture(texture1);
	player2.LoadTexture(texture2);

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
