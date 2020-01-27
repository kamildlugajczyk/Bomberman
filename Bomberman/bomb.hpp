#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "block.hpp"

class Bomb : public Block
{
	float explodeTime;
	sf::Texture bombTexture;

public:

	Bomb();

	void Update (const sf::Time deltaTime) override;
	virtual void SetUp() override;
};