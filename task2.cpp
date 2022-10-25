#include <iostream>


void multFunc(int &summ,char a[], char b[]) {
	int tens = 1;
	for (int i = 0; i < strlen(b); ++i) {
		int temp_tens = 1;
		for (int j = 0; j < strlen(a); ++j) {
			summ += (a[strlen(a) - j - 1] - 48) * (b[strlen(b) - i - 1] - 48) * tens * temp_tens;
			temp_tens *= 10;
		}
		tens *= 10;
	}
}
int main() {
	char a[1000];
	char b[1000];
	
	char proc;
	std::cout << "What procedure (+ or &)?: ";
	
	std::cin >> proc;
	std::cin >> a;
	std::cin >> b;

	int summ = 0;
	if (strlen(a) < strlen(b)) {
		char temp[1000];
		strcpy_s(temp, a);
		strcpy_s(a, b);
		strcpy_s(b, temp);
	}
	if (proc == '+') {
		char one[2] = { '1', '\0' };
		multFunc(summ, a, one);
		multFunc(summ, b, one);
	}
	else if(proc == '*') {
		multFunc(summ, a, b);
	}
	else {
		std::cout << "Wrong input";
	}

	std::cout << summ;
	return 0;
}