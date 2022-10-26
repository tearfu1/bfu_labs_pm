#include "procFunc.h"
#include <iostream>
#include <vector>

// (std::vector <int> *parm, const int elemsCount) в качестве параметра лежит указатель на первый элемент матрицы(строку)
// —уть работы: в векторе элементы лежат друг за другом, значит можно их перебирать через ++parm.
// “ак же нам нужны элементы строк, таким образом создаетс€ вектор a, который равен строке, на которую отсылает *parm
// » его элементыуже можно перебирать.
// функци€ проверки удовлетворени€ матрицей условий
bool isFit(std::vector <int> *parm, const int elemsCount)
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
// обработка матрицы
// *parm = a - в матрицу записываем строку(столбец в исходной матрице (matrix)) уже обработанную
void procFunc(std::vector<int>* parm, const int elemsCount)
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
