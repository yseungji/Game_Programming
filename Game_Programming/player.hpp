#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
	Player(sf::Vector2f pos, float size, sf::Color color, float speed); //생성자(변수 초기화)

	void Update(); //플레이어의 동작

	void Draw(sf::RenderWindow& window); //플레이어 그리기

	sf::Vector2f GetPosition();
private:
	void ProcessInput(); //키보드 입력 처리
private:
	sf::Vector2f position; //위치
	float speed; //속도
	float size; //크기
	sf::RectangleShape shape; //모양
	sf::Color color; //색깔
};

