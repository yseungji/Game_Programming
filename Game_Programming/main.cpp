#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#ifdef _DEBUG
#define DBG_NEW new( _NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define DBG_NEW new
#endif


#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "enemy.hpp"
#include "bullet.hpp"
#define MAX 10
#include <iostream>
#include <vector>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	srand(time(NULL));
	int i;
	int videoX = 1024, videoY = 768;
	
	Player p(sf::Vector2f(10.f,10.f),30,sf::Color::Magenta,0.005);
	std::vector <enemy*> enemies;
	//bullet bul(sf::Vector2f(5.f, 5.f), sf::Vector2f(1,0), sf::Color::Green, 1.0f, 10);
	std::vector <bullet*> bullets;
	float bulletFirePeriod = 0.5f;
	float bulletFireTimer = 0.0;

	sf::Clock deltaTimeClock;

	for (i = 0; i < MAX; i++) {
		float randomx = videoX - 100; 
		float randomy = rand() % videoY;
		enemy* e = new enemy{ sf::Vector2f(randomx, randomy), 0.3f, 30.f, sf::Color::Blue,&p };
		enemies.push_back(e);
	}
	
	sf::RenderWindow window(sf::VideoMode(videoX, videoY), "SFML works!");
	window.setFramerateLimit(60);
	sf::Font font;
	
	if (!font.loadFromFile("../resources/font/arial.ttf"))
	{
		std::cout << "Font Loading Error!" << std::endl;
	}
	
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		} 
		
		float dt = deltaTimeClock.restart().asSeconds();
		bulletFireTimer += dt;
		if (bulletFireTimer > bulletFirePeriod) {
			bulletFireTimer = 0.f;
			//bullet 객체 생성
			bullet* b = new bullet(p.GetPosition(), sf::Vector2f(1, 0), sf::Color::Green, 1.0f, 10);
			bullets.push_back(b);
		}
		p.Update();
		for(i=0;i<enemies.size();i++)
			enemies[i]->Update();
		for (i = 0; i < bullets.size(); i++)
			bullets[i]->Update();

		window.clear(); //지우기
		p.Draw(window);
		for (i = 0; i < enemies.size(); i++)
			enemies[i]->Draw(window);
		for (i = 0; i < bullets.size(); i++)
			bullets[i]->Draw(window);

		window.display();//표시하기
	}	
	
	for (i = 0; i < enemies.size(); i++) {
		delete enemies[i];
	}
	for (i = 0; i < bullets.size(); i++) {
		delete bullets[i];
	}
	return 0;
}
