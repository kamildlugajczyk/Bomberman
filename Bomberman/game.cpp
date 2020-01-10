#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.hpp"

Game::Game()
{
	windowSize.x = 800;
	windowSize.y = 600;
	window.create(sf::VideoMode(windowSize.x, windowSize.y), "Bomberman");

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
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
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
		sprite.setTextureRect(sf::IntRect(0, 0, 80, 120));
		sprite.setScale(0.5, 0.5);

		//sprite.move(sf::Vector2f(5.f, 5.f));

		window.clear(sf::Color::Black);

		window.draw(sprite);

		window.display();

	}
}
