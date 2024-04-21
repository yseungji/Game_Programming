#include <SFML/Graphics.hpp>

class Player;

class enemy {
public:
	enemy(sf::Vector2f pos, float speed, float size, sf::Color color, Player* player);
	enemy(); //기본 생성자도 필요
	
	void Update();

	void Draw(sf::RenderWindow &window);

	sf::Vector2f GetPosition();
private:
	void UpdatePosition();
private:
	sf::Vector2f position;
	Player* playerref;
	sf::CircleShape shape;
	float speed;
	float size;
	sf::Color color;
};