/*
#include <SFML/Graphics.hpp>
#include <iostream>
#define MAX 30

int main()
{
	srand(time(NULL));
	int i;
	float x = 0.03f;
	float rectwidth = 30.0f;
	float rectheight = 30.0f;
	float rectX = 0;
	float rectY = 0;
	int videoX = 1024;
	int videoY = 768;

	sf::RenderWindow window(sf::VideoMode(videoX, videoY), "SFML works!");
	sf::Font font;

	if (!font.loadFromFile("../resources/font/arial.ttf"))
	{
		std::cout << "Font Loading Error!" << std::endl;
	}
	sf::RectangleShape shape;


	for (i = 0; i < MAX; i++) {
		rectheight = rand() % 90 + 10;
		rectwidth = rand() % 90 + 10;
		shape.setSize(sf::Vector2f(rectheight, rectwidth));
		sf::Color c = sf::Color::Red;
		shape.setFillColor(c);
		sf::Vector2f vec;
		vec.x = rand() % videoX;
		vec.y = rand() % videoY;
		shape.setPosition(vec);
	}



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			shape.move(-0.1, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			shape.move(0.1, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			shape.move(0, -0.1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			shape.move(0, 0.1);
		}


		window.clear(); //지우기
		for (i = 0; i < MAX; i++) {
			window.draw(shape); //그리기
		}
		window.display();//표시하기
	}

}*/