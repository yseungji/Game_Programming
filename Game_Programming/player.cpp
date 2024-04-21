#include "player.hpp"

Player::Player(sf::Vector2f pos, float size, sf::Color color, float speed)
	: position{pos}, size{size}, color{color}, speed{speed}
{
	shape.setPosition(pos);
	shape.setFillColor(color);
	shape.setSize(sf::Vector2f(size, size));


}
void Player::Update() {
	Player::ProcessInput();
	shape.setPosition(position.x, position.y);
}
void Player::ProcessInput() {
	float playerspeed = 0.5;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		//P.move(-playerspeed, 0);
		position.x -= playerspeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		//P.move(playerspeed, 0);
		position.x += playerspeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		//P.move(0, -playerspeed);
		position.y -= playerspeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		//P.move(0, playerspeed);
		position.y += playerspeed;
	}
}
void Player::Draw(sf::RenderWindow& window) {
	window.draw(shape);
}

sf::Vector2f Player::GetPosition()
{
	return position;
}
