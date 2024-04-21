#pragma once
#include <SFML/Graphics.hpp>
#include "player.hpp"
class bullet {
public:
	//»ý¼ºÀÚ
	bullet(sf::Vector2f pos,sf::Vector2f direction ,sf::Color color, float speed, float size);
	
	void Draw(sf::RenderWindow& window);
	
	void Update();
	sf::Vector2f GetPosition() { return position; }
private:
	void UpdatePosition();
private:
	float speed;
	sf::Vector2f position;
	sf::Vector2f direction;
	sf::Color color;
	sf::CircleShape shape;
	float size;
};