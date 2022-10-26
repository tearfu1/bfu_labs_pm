#include "procFunc.h"
#include <iostream>
#include <vector>

// (std::vector <int> *parm, const int elemsCount) � �������� ��������� ����� ��������� �� ������ ������� �������(������)
// ���� ������: � ������� �������� ����� ���� �� ������, ������ ����� �� ���������� ����� ++parm.
// ��� �� ��� ����� �������� �����, ����� ������� ��������� ������ a, ������� ����� ������, �� ������� �������� *parm
// � ��� ����������� ����� ����������.
// ������� �������� �������������� �������� �������
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
// ��������� �������
// *parm = a - � ������� ���������� ������(������� � �������� ������� (matrix)) ��� ������������
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
