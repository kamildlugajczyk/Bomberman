#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "block.hpp"

class Explosion : public Block
{
	float flameTime;

	//bool isDestroyed = false;

public:
	sf::Texture explosionTexture;

	Explosion();

	void Update(const sf::Time deltaTime) override;

	/*bool exploded = false;

	bool IsExploded() { return exploded; };

	void Explode() { exploded = true; };*/
};