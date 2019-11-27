#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Game
{
	sf::RenderWindow window;
	bool isOver;


public:
	Game();

	void play();
};