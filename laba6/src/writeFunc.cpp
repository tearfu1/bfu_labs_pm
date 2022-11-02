#include "writeFunc.h"
#include <vector>
#include <fstream>
#include <string>

namespace FuncNS {
    void writeFunc(std::vector<int>* parm, const int elemsCount)
    {
        std::string path = "ans.txt";
        std::fstream fs;
        fs.open(path, std::fstream::out);
        for (int itemNumber = 0; itemNumber < elemsCount; ++itemNumber, ++parm)
        {
            std::vector <int> a = *parm;
            for (int i = 0; i < elemsCount; ++i) {
                fs << a[i] << " ";
            }
            fs << std::endl;
        }
        fs.close();
    }
}