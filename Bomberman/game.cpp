#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "player.hpp"

Game::Game()
{
	windowSize.x = 800;
	windowSize.y = 600;
	window.create(sf::VideoMode(windowSize.x, windowSize.y), "Bomberman");

	window.setFramerateLimit(60);

	player.SetPosition(sf::Vector2f( 200, 200));

	isOver = false;
}

void Game::Draw()
{
	player.Draw(window);
}

void Game::play()
{
	sf::Clock clock;
	sf::Time time;

	// tymczasowe
	sf::Texture texture;
	if (!texture.loadFromFile("res/img/bomberman.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
	}
	//--------------------------

	player.LoadTexture(texture);

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

		player.Move(time);
		player.Update(time);
		Draw();

		//std::cout << "x = " << player.GetPosition().x << "   y = " << player.GetPosition().y << std::endl;

		window.display();

	}
}
