#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class EndGameScreen
{
	sf::Text mainText;									// tekst glowny wyswietlany u gory
	sf::Text subText;									// tekst dodatkowy wyswietlany pod mainText

public:

	/* Metoda rysujaca mainText oraz subText
	@param window okno gry */
	void Draw(sf::RenderWindow & window);

	/* Metoda wywietlajaca informacje o wygranej gracza 1 */
	void DisplayPlayer1Win();

	/* Metoda wywietlajaca informacje o wygranej gracza 2 */
	void DisplayPlayer2Win();

	/* Metoda wczytujaca czcionke podana w parametrze
	@param font wybrana czcionka */
	void LoadFont(const sf::Font & font);
};