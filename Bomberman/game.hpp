#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "player.hpp"

class Game
{
	sf::RenderWindow window;
	sf::Vector2f windowSize;
	Player player {1,1,1,1};
	bool isOver;


public:
	Game();

	void Draw();

	void play();
};