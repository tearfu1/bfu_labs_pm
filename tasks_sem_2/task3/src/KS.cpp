#include "KS.h"
#include <SFML/Graphics.hpp>
#include <cmath>

KinematicSolver::KinematicSolver(sf::RenderWindow* window, double sizeL1, double sizeL2) {
	this->window = window;
	this->len_L3 = 0;
	float jointAngle0 = 0;
	float jointAngle1 = 0;
	
	this->dot.setSize(sf::Vector2f(3.f, 3.f));

	this->L1.setSize(sf::Vector2f(sizeL1, 5.f));
	this->L1.setFillColor(sf::Color(100, 250, 50));
	this->L1.setPosition(10, 750);
	this->len_L1 = sizeL1;

	this->L2.setSize(sf::Vector2f(sizeL2, 5.f));
	this->L2.setFillColor(sf::Color(139, 0, 255));
	this->L2.setPosition(10 + sizeL1, 750);
	this->len_L2 = sizeL2;

	this->dot1.setRadius(6.f);
	this->dot1.setFillColor(sf::Color(139, 0, 25));
	this->dot1.setPosition(4,747);
	
	this->dot2.setRadius(6.f);
	this->dot2.setFillColor(sf::Color(139, 0, 25));
	this->dot2.setPosition(4 + sizeL1,747);

}

double KinematicSolver::Solve(double x, double y)
{
	this->dot.setPosition(10+x, 750-y);
	this->len_L3 = sqrt(x * x + y * y);
	this->L3.setSize(sf::Vector2f(len_L3, 5.f));

	this->len_L3 = sqrt(x * x + y * y);

	float angle2 = atan2(y, x) * 180 / acos(-1);

	if (len_L1 + len_L2 < len_L3)
	{
		this->jointAngle0 = angle2;
		this->jointAngle1 = 0.f;
	}
	else 
	{
		float cosAngle0 = ((len_L3 * len_L3) + (len_L1 * len_L1) - (len_L2 * len_L2)) / (2 * len_L3 * len_L1);
		float angle0 = acos(cosAngle0) * 180 / acos(-1);

		float cosAngle1 = ((len_L2 * len_L2) + (len_L1 * len_L1) - (len_L3 * len_L3)) / (2 * len_L2 * len_L1);
		float angle1 = acos(cosAngle1) * 180 / acos(-1);

		this->jointAngle0 = abs(angle2 - angle0);	// ”гол A
		this->jointAngle1 = 180.f - angle1;	// ”гол B
	}
	
	return 0.0;
}

void KinematicSolver::update()
{
	this->L1.setRotation(-jointAngle0);
	this->L2.setPosition(10+cos(jointAngle0 * acos(-1) / 180) * len_L1, 750 - sin(jointAngle0 * acos(-1) / 180) * len_L1);
	this->L2.setRotation(-(jointAngle0 + jointAngle1));
	this->dot2.setPosition(4 + cos(jointAngle0 * acos(-1) / 180) * len_L1, 747 - sin(jointAngle0 * acos(-1) / 180) * len_L1);
}



void KinematicSolver::draw()
{
	this->window->draw(this->L1);
	this->window->draw(this->L2);
	this->window->draw(this->dot2);
	this->window->draw(this->dot1);
	this->window->draw(this->dot);
}


