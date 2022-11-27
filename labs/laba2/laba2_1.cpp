#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
	int a,b,c;
	std::cout << "Input natural numbers A, B, C (separated by a space): ";
	std::cin >> a >> b >> c;
	if (a < b && b < c) {
		std::cout << "Due to A < b < C the result is: " << (c-b-a);
	}
	else if ((a % c) == 0) {
		std::cout << "Due to A is a multiple of C the result is: " << (a/c) + b;
	}
	else {
		std::cout << "Due to your inputs don't match any conditions the result is: " << a+b+c;
	
	}
	
}
