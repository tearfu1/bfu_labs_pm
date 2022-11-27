#include "readFunc.h"
#include <fstream>


std::vector<std::vector<int>> readFunc(std::string path)
{
    std::fstream fs;
    fs.open(path, std::fstream::in);
    int n;
    fs >> n;
    
    std::vector <std::vector<int>> matrix(n, std::vector<int>(n));
   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fs >> matrix[i][j];
        }
        if (fs.eof()) break;
    }
    fs.close();
    return matrix;
}
