#pragma once
#include <vector>
#include <string>

namespace Func {

	bool isFit(std::vector <int>* parm, const int elemsCount);
	void procFunc(std::vector <int>* parm, const int elemsCount);
	std::vector <std::vector<int>> readFunc(std::string path);
	void writeFunc(std::vector <int>* parm, const int elemsCount);
}