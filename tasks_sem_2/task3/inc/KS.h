#pragma once
#include <SFML/Graphics.hpp>
class KinematicSolver {
	sf::RenderWindow* window;
	float jointAngle0;
	float jointAngle1;
	
	sf::RectangleShape L1;
	double len_L1;
	sf::RectangleShape L2;
	double len_L2;
	sf::RectangleShape L3;
	double len_L3;

	sf::RectangleShape dot;
	sf::CircleShape dot1;
	sf::CircleShape dot2;

public:
	KinematicSolver(sf::RenderWindow* window, double sizeL1, double sizeL2);
	void draw();
	void update();
	double Solve(double x, double y);

};