#include <iostream>

void multFunc(int summ[], char a[], char b[]) {
	for (int i = 0; i < strlen(b); ++i) {
		for (int j = 0; j < strlen(a); ++j) {
			summ[2001-i-j-1] += (a[strlen(a) - j - 1] - 48) * (b[strlen(b) - i - 1] - 48);
		}
	}
}
void printFunc(int summ[]) {
	bool flag = false;
	for (int i = 0; i < 2001; ++i) {
		if (summ[i] == 0 && not flag) {
			continue;
		}
		else {
			flag = true;
			std::cout << summ[i];
		}
	}
}
void normChunk(int summ[]) {
	for (int i = 2000; i > 0; --i) {
		if (summ[i] > 9) {
			summ[i - 1] += summ[i] / 10;
			summ[i] = summ[i] % 10;
		}
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

	int summ[2001] = {0};
	if (proc == '+') {
		char one[2] = { '1', '\0' };
		multFunc(summ, a, one);
		multFunc(summ, b, one);
	}
	else if (proc == '*') {
		multFunc(summ, a, b);
	}
	else {
		std::cout << "Wrong input";
	}
	normChunk(summ);
	printFunc(summ);
	return 0;
}