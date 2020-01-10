#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Game
{
	sf::RenderWindow window;
	sf::Vector2f windowSize;
	bool isOver;


public:
	Game();

	void play();
};