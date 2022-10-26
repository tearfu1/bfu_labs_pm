#include "AllFunc.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace Func;


bool Func::isFit(std::vector<int>* parm, const int elemsCount)
{
    for (int itemNumber = 0; itemNumber < elemsCount; ++itemNumber, ++parm)
    {
        std::vector <int> a = *parm;
        if (a[itemNumber] > 0) {
            int temp = a[itemNumber];
            bool flag = false;
            while (temp > 0) {
                flag = (temp % 10 == 3) || (temp % 10 == 5);
                temp /= 10;
                if (flag) break;
            }
            if (!flag)return false;
        }
        else return false;
    }
    return true;
}

void Func::procFunc(std::vector<int>* parm, const int elemsCount)
{
    for (int itemNumber = 0; itemNumber < elemsCount; ++itemNumber, ++parm)
    {
        int minim = 99999;
        int min_ind = 0;
        int summa = 0;
        std::vector <int> a = *parm;
        for (int i = 0; i < elemsCount; ++i) {
            summa += a[i] * a[i];
            if (a[i] < minim) {
                minim = a[i];
                min_ind = i;
            }
        }
        a[min_ind] = summa - minim * minim;
        *parm = a;
    }
}

std::vector<std::vector<int>> Func::readFunc(std::string path)
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

void Func::writeFunc(std::vector<int>* parm, const int elemsCount)
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
