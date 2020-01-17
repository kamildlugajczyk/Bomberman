#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


class Map
{
	sf::Sprite tile;
	std::vector<std::vector<unsigned int>> gameMap;
	std::vector<std::vector<sf::Sprite>> spriteSet;
	sf::Texture textureSet;
	int tileSize;

public:
	Map();

	void loadTexture(const sf::Texture & texture);

	void Update();

	void Draw(sf::RenderWindow & window);
};