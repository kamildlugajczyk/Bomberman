#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.hpp"

Game::Game()
{
	window.create(sf::VideoMode(800, 600), "Bomberman");
	window.setFramerateLimit(60);

	isOver = false;
}

void Game::play()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
				window.close();
		}

		sf::Texture texture;
		if (!texture.loadFromFile("res/img/bomberman.png"))
		{
			std::cout << "Load failed! " << std::endl;
			getchar();
		}

		sf::Sprite sprite;
		sprite.setTexture(texture);
		//sprite.setTextureRect(sf::IntRect(0, 0, 500, 500));
		sprite.setScale(0.5, 0.5);

		window.clear(sf::Color::Black);

		window.draw(sprite);

		window.display();

	}
}
