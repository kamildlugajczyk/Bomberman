#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class EndGameScreen
{
	sf::Text mainText;
	sf::Text subText;

public:
	void Draw(sf::RenderWindow & window);

	void DisplayPlayer1Win();

	void DisplayPlayer2Win();

	void LoadFont(const sf::Font & font);
};