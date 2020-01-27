#include <iostream>
#include <SFML/Graphics.hpp>

#include "end_game_screen.hpp"

void EndGameScreen::Draw(sf::RenderWindow & window)
{
	window.draw(mainText);
	window.draw(subText);
}

void EndGameScreen::DisplayPlayer1Win()
{
	mainText.setPosition(270, 200);
	mainText.setCharacterSize(50);

	subText.setPosition(270, 400);
	subText.setCharacterSize(25);

	mainText.setString("Player 1 wins!");
	subText.setString("Press ESC to exit");
}

void EndGameScreen::DisplayPlayer2Win()
{
	mainText.setPosition(270, 200);
	mainText.setCharacterSize(50);

	subText.setPosition(270, 400);
	subText.setCharacterSize(25);

	mainText.setString("Player 2 wins!");
	subText.setString("Press ESC to exit");
}

void EndGameScreen::LoadFont(const sf::Font & font)
{
	mainText.setFont(font);
	subText.setFont(font);
}
