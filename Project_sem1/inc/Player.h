#pragma once
#include <SFML/Graphics.hpp>

class Paddle {
	sf::RenderWindow* window;
	sf::RectangleShape rectangle;
	sf::RectangleShape line;
	int y, player, score;
	float speed;
	sf::Vector2f pPos = rectangle.getPosition();
	sf::Font font;
public:
	Paddle(sf::RenderWindow* window, int player);
	void draw();
	void update(float time);
	auto getPosition();
	void setScore();
};

class Ball
{
	sf::RenderWindow* window;
	sf::RectangleShape circle;
	int x, y;
	float dx, dy,speed;
public:
	Ball(sf::RenderWindow* window);
	void draw();
	void update(int time, Paddle* paddle1,Paddle* paddle2);
};