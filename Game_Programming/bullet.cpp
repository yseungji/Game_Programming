#pragma once
#include "bullet.hpp"

bullet::bullet(sf::Vector2f pos, sf::Vector2f direction, sf::Color color, float speed, float size)
	: position{ pos },direction{direction}, color{ color }, speed{ speed }, size{ size }
{
	shape.setRadius(size);
	shape.setPosition(pos.x, pos.y);
	shape.setFillColor(color);
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(3.f);
}

void bullet::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void bullet::Update()
{
	UpdatePosition();
	shape.setPosition(position);
}

void bullet::UpdatePosition()
{
	position += direction * speed;
}
