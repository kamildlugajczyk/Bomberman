#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "block.hpp"

class Explosion : public Block
{
	sf::Texture explosionTexture;
	float flameTime;

public:

	Explosion();

	void Update(const sf::Time deltaTime) override;
	virtual void SetUp() override;
};