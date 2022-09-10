#include <iostream>
#include <math.h>

int main()
{
	int n;
	std::cin >> n;
	double mult = 1;
	double minim = 9999;
	int minim_index = 0;
	for (int i = 0; i < n; ++i) {
		double t;
		std::cout << "Input a real number: ";
		std::cin >> t;
		if ((fmod(t, 1) != 0) && (t < 0)) {
			mult *= t;
			if (t < minim) {
				minim = t;
				minim_index = i;
				}
		}
	}
	std::cout << "Product: " << mult << "\n";
	std::cout << "Minimum: " << minim << "\n";
	std::cout << "Minimum index: " << minim_index << "\n";
	return 0;
}
