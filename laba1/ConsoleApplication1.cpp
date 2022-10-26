#include <iostream>
#include <cmath>
#include <iomanip>
#define PI acos(-1)

int main()
{
	double r = 0;

	std::cout << "Input the raduis of the circle: ";
	std::cin >> r;
    std::cout << std::setprecision(15) << "The area of the circle is: " << PI*pow(r,2);
}
