#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <Windows.h>
#include <clocale>

int main() {
	std::string a;
	std::map<char, int> s;
	std::cout << "Input a string: ";
	std::cin >> a;
	setlocale(LC_CTYPE, "Russian");

	for (int i = 0; i < a.size(); ++i) {
		char t;
		t = toupper(a[i]);
		if (s.find(t) != s.end()) {
			s[t] += 1;
		}
		else {
			s[t] = 1;
		}
	}
	
	
	int maxim = 0;
	std::vector <char> max_let(15);
	max_let.clear();
	
	
	for (auto now : s) {
		if (now.second > maxim) {
			maxim = now.second;
			max_let.clear();
			max_let.push_back(now.first);
		}
		else if (now.second == maxim) {
			max_let.push_back(now.first);
		}
	}
	std::cout << "Most common letter(s): ";
	for (auto now : max_let) {
		std::cout << now << " ";
	}
	std::cout << "appeared " << maxim << " times";
	return 0;
}