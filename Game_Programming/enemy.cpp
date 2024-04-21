#pragma once
#include "enemy.hpp"
#include "player.hpp"
#include <iostream>


enemy::enemy(sf::Vector2f pos, float speed, float size, sf::Color color, Player* player)
	: position{ pos }, speed{ speed }, size{ size }, color{ color }, playerref{ player }
{
	shape.setRadius(size);
	shape.setPosition(pos.x, pos.y);
	shape.setFillColor(color);
	shape.setOutlineColor(sf::Color::Red);
	shape.setOutlineThickness(5.f);
}
enemy::enemy() 
	:playerref{NULL}
{
	
}
void enemy::Update()
{
	enemy::UpdatePosition();
	shape.setPosition(position);
}

void enemy::Draw(sf::RenderWindow &window)
{
	window.draw(shape);
}

void enemy::UpdatePosition()
{
	sf::Vector2f pos = playerref->GetPosition();
	float speed = float(rand() % 50) / 100;
	float lenx = -pos.x + position.x;
	float leny = -pos.y + position.y;
	float len = sqrt(lenx * lenx + leny * leny);
	lenx /= len;
	leny /= len;
	
	position.x -= lenx * speed;
	position.y -= leny * speed;
	
}
