#include <iostream>
#include <SFML/Graphics.hpp>

#include "background.hpp"

Background::Background()
{
	if (!backgroundTexture.loadFromFile("res/img/background.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
	}
}

void Background::SetUp()
{
	LoadTexture(backgroundTexture);
}
