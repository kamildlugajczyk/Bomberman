#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class GraphicObject
{
protected:
	sf::Vector2f position;
	sf::FloatRect collisionBox;
	sf::Sprite sprite;

public:
	/* virtual */ sf::Vector2f GetPosition();

	void SetPosition(sf::Vector2f & position);

	sf::FloatRect GetCollisionBox();

	void SetTexture(sf::IntRect & dimensions);

	void LoadTexture(const sf::Texture & texture);

	virtual void UpdateCollisionBox() = 0 ;

	void Draw(sf::RenderWindow & window);
};