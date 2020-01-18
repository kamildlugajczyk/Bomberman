#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "player.hpp"
#include "map.hpp"

class Game
{
	sf::RenderWindow window;
	sf::Vector2f windowSize;
	Player player1 {1,1,1,1};
	Player player2 {1,1,1,1};
	Map map;
	bool isOver;

public:
	Game();

	//void LoadResoures();

	void Draw();

	void play();
};