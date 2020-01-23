#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "graphic_object.hpp"

class Block : public GraphicObject
{
	enum BlockType { solidBlock, breakableBlock, bacgroundBlock, bombBlock };
	//sf::Sprite block_sprite;


	/*bool isCollideable; 
	bool isInjurious; */

public:
	bool destroyed = false;

	virtual void Update(const sf::Time deltaTime);

	bool IsDestroyed() { return destroyed; };

	void Destroy() { destroyed = true; };

	bool exploded = false;

	bool IsExploded() { return exploded; };

	void Explode() { exploded = true; };
};