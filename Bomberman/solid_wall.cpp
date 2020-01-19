#include <iostream>
#include <SFML/Graphics.hpp>

#include "solid_wall.hpp"

SolidWall::SolidWall()
{
	if (!solid_texture.loadFromFile("res/img/SolidBlock.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
	}
}
