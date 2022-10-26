#include <iostream>
#include <vector>

int main()
{ 
	int n,m;
	std::cout << "Input amount of strings: ";
	std::cin >> n;
	std::cout << "Input amount of rows: ";
	std::cin >> m;
	std::vector<std::vector<int> > a(n, std::vector<int>(m,0));
	
	int maxim_sum = 0;
	int max_sum_str_ind = 0;
	
	//считка данных + сумма
	for (int i = 0; i < n; ++i) {
		int temp_sum = 0;
		for (int j = 0; j < m; ++j) {
			std::cout << "Input a number: ";
			std::cin >> a[i][j];
			temp_sum += a[i][j];
		}
		if (abs(temp_sum) > maxim_sum) {
			maxim_sum = abs(temp_sum);
			max_sum_str_ind = i;
		}
	}
	std::cout << "Array before applying the algorithm:\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << a[i][j] << " ";
		}
		std::cout << "\n";
	}
	//замена чисел в строкес наибольшей суммой
	for (int i = 0; i < m; ++i) {
		a[max_sum_str_ind][i] = 9999;
	}
	//вывод
	std::cout << "Array after applying the algorithm:\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << a[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "Maximum absolute summ of string: " << maxim_sum << "\n";
	std::cout << "It's index: " << max_sum_str_ind + 1 << "\n";
	return 0;
}