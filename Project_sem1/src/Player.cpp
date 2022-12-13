#include "Player.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>


//ракетки
Paddle::Paddle(sf::RenderWindow* window, int player) {
	this->score = 0;
	this->y = 400;
	this->player = player;
	speed = 5;

	this -> font.loadFromFile("Calibri.ttf");
	
	this->window = window;
	this->rectangle.setSize(sf::Vector2f(10, 100));
	this->rectangle.setSize(sf::Vector2f(10, 100));

	this->line.setSize(sf::Vector2f(3, 20));
	if (this->player == 1) {
		this->rectangle.setPosition(20, this->y);
	}
	else {
		this->rectangle.setPosition(770, this->y);
	}
}void Paddle::draw() {
	this->window->draw(this->rectangle);
	
	sf::Text text(" ", this->font);
	text.setString(std::to_string(score));
	if (player == 1) {
		text.setPosition(200, 0);
		this->window->draw(text);
	}
	else {
		text.setPosition(600, 0);
		this->window->draw(text);
	}
	
	for (int i = 0; i < this->window->getSize().y ; i += 50) {
		this->line.setPosition(400, 20+i);
		this->window->draw(this->line);
	}
}
void Paddle::update(float time) {
	this->pPos = this->rectangle.getPosition();
	if (this->player == 2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (this->pPos.y > 0) rectangle.move(0, -speed*time*0.09);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (this->pPos.y < 700) rectangle.move(0, speed*time * 0.09);
		}
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			if (this->pPos.y > 0) rectangle.move(0, -speed * time * 0.09);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (this->pPos.y < 700) rectangle.move(0, speed * time * 0.09);
		}
	}
}
auto Paddle::getPosition() {
	return rectangle.getPosition();
}
void Paddle::setScore() {
	this->score += 1;
}

Ball::Ball(sf::RenderWindow* window) {
	this->window = window;
	this ->speed = 5*0.9;
	this->x = 397;
	this->y = 400;
	this->circle.setSize(sf::Vector2f(10, 10));
	this->circle.setPosition(this->x, this->y);
	this->circle.setFillColor(sf::Color::Red);
	
	this->dx = 0;
	this->dy = 0;
	
}

void Ball::draw() {
	this->window->draw(this->circle);
}

void Ball::update(int time,Paddle* paddle1,Paddle* paddle2) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		//circle.setPosition(this->x, this->y);
		dx = speed *pow(-1, rand() % 100);
		dy = speed* pow(-1, rand() % 100);
	}
	sf::Vector2f bPos = this->circle.getPosition();
	sf::Vector2f p1Pos = paddle1->getPosition();
	sf::Vector2f p2Pos = paddle2->getPosition();
	
	if (bPos.y < 0) {
		this->dy = this->speed;
	}
	if (bPos.y > 800-10) {
		this->dy = -this->speed;
	}
	if (bPos.x > 800 - 10 || bPos.x < 0)
	{
		if (bPos.x > 800 - 10) {
			paddle1->setScore();
		}
		else {
			paddle2->setScore();
		}
		 dy = 0;
		 dx = 0;
		 circle.setPosition(this->x, this->y);
	}
	if (bPos.y >= p2Pos.y && bPos.y <= p2Pos.y+100) {
		if (bPos.x >= p2Pos.x-10) {
			circle.setPosition(circle.getPosition().x - 5, circle.getPosition().y - 5);
			this->dx = -this->dx;
		}
	}
	if (bPos.y >= p1Pos.y && bPos.y <= p1Pos.y + 100) {
		if (bPos.x <= p1Pos.x+10) {
			circle.setPosition(circle.getPosition().x+5, circle.getPosition().y+5);
			this->dx = -this->dx;
		}
	}
	this->circle.move(dx*0.05*time, dy*0.05*time);

}




