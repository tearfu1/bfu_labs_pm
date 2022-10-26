#include <iostream>
#include <vector>

int digits_sum(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int first_digit(int n) {
	int k = 0;
	while (n > 0) {
		k = n % 10;
		n /= 10;
	}
	return k;

}
std::vector <int> sort_by_digits(std::vector <int> a, int n) {
	for (int i = 1; i < n; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			int j_sum = digits_sum(a[j]);
			int pr_sum = digits_sum( a[j+1] );
			int temp = 0;
			
			if (pr_sum < j_sum) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
			else if (pr_sum == j_sum) {
				if (first_digit(a[j+1]) < first_digit(a[j])) {
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}
	return a;
}
int main()
{ 
	int n;
	
	std::cout << "Input length of subsequence: ";
	std::cin >> n;

	std::vector <int> a(n);

	for (int i = 0; i < n; ++i) {
		std::cout << "Input a number: ";
		std::cin >> a[i];
	}
	std::cout << "Subsequence before:\n";
	for (int i = 0; i < n; ++i) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
	a = sort_by_digits(a, n);

	std::cout << "Sorted subsequence: \n";
	for (int i = 0; i < n; ++i) {
		std::cout << a[i] << " ";
	}
	return 0;
}