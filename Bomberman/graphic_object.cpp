#include <iostream>
#include "graphic_object.hpp"



sf::Vector2f GraphicObject::GetPosition()
{
	return this->position;
}

void GraphicObject::SetPosition(sf::Vector2f & position)
{
	this->position = position;
}

sf::FloatRect GraphicObject::GetCollisionBox()
{
	return this->collisionBox;
}

void GraphicObject::SetTexture(sf::IntRect & dimensions)
{
	sprite.setTextureRect(dimensions);
}

void GraphicObject::LoadTexture(const sf::Texture & texture)
{
	sprite.setTexture(texture);
	//sprite.setScale()																// zastanowic sie
}

void GraphicObject::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}
