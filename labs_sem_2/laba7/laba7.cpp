#include <iostream>
#include <string>
#include <cmath>

class Shape 
{
protected:
	std::string m_color;
	int coord_x = 0;
	int coord_y = 0;
public:
	virtual double Area() = 0;
	void setPosition(int& x, int& y) {
		this->coord_x = x;
		this->coord_y = x;
	}
	virtual ~Shape() {}
};

class Triangle : public Shape 
{
private:
	double side_a;
	double side_b;
	double side_c;
public:
	Triangle(const std::string& color, const double& a = 0, const double& b = 0, const double& c = 0)
	{
		this->m_color = color;
		this->side_a = a;
		this->side_b = b;
		this->side_c = c;
	}
	double Area() override
	{
		double p = (side_a + side_b + side_c) / 2;
		return sqrt(p * (p - side_a) * (p - side_b) * (p - side_c));
	}
	~Triangle() {}
};

class Rectangle : public Shape
{
private:
	double side_a;
	double side_b;
public:
	Rectangle (const std::string& color, const double& a = 0, const double& b = 0)
	{
		this->m_color = color;
		this->side_a = a;
		this->side_b = b;
	}
	double Area() override
	{
		return side_a * side_b;
	}
	~Rectangle() {}
};

class Circle : public Shape
{
private:
	double radius;
public:
	Circle(const std::string& color, const double& r = 0)
	{
		this->m_color = color;
		this->radius = r;
	}
	double Area() override
	{
		return acos(-1) * pow(radius, 2);
	}
	~Circle(){}
};
int main() {
	Rectangle rl("red", 2,2);
	Triangle tl("red", 2,2,2);
	Circle cl("red", 2);
	std::cout << cl.Area() << " "<< tl.Area() << " "<< cl.Area();
	return 0;
}
