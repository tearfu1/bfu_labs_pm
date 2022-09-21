#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

//проверка на все разные буквы в слове
bool isdiff(std::string n) {
	std::string pr = "";
	for (int i = 0; i < n.size(); ++i) {
		if (pr.find(n[i]) != -1) {
			return false;
		}
		else {
			pr.push_back(n[i]);
		}
	}
	return true;
}

//сортировка по длине слова
std::vector <std::string> WordLenSort(std::vector <std::string> word) {
	for (int i = 1; i < word.size(); ++i) {
		for (int j = i; j >= 1; --j) {
			if (word[j].length() < word[j - 1].length()) {
				std::swap(word[j], word[j-1]);
			}
			else {
				break;
			}
		}
	}
	return word;
}

int main()
{
	int n;
	std::string msg;
	std::string path = "test.txt";
	std::fstream fs;
	fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);
	fs >> n;
	
	std::vector <std::string> words(n);
	words.clear();

	std::string min_word = "";
	//считывание из и нахождение слов, подходящих под условия
	while (!fs.eof()) {
		msg = "";
		fs >> msg;
		if (isdiff(msg)) {
			//проверка на вторичность элементы
			if (std::find(words.begin(), words.end(), msg) == words.end()) { 
				if (words.size() < n) {
					words.push_back(msg);
				}
				else if (words.size() == n) {
					for (int i = 0; i < n; ++i) {
						if (msg.length() > words[i].length()) {
							words[i] = msg;
							break;
						}
					}
				}
			}
		}
	}
	fs.close();
	//запись в другой файл
	path = "test2.txt";
	fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);
	
	words = WordLenSort(words);
	for (int i = words.size()-1; i >= 0; --i) {
		fs << words[i] << std::endl;
	}
	fs.close();
	return 0;
}