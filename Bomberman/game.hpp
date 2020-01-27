#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "player.hpp"
#include "map.hpp"
#include "end_game_screen.hpp"

class Game
{
	sf::RenderWindow window;
	sf::Vector2f windowSize;
	Player player1{"Player 1"};
	Player player2{"Player 2"};
	Map map;
	EndGameScreen endGameScreen;
	sf::Font font;
	bool isOver;

public:
	Game();

	void Update(const sf::Time deltaTime);

	void Draw();

	void play();
};