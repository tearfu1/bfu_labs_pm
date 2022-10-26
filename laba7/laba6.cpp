#include <iostream>
#include <vector>
#include <string>
#include "readFunc.h"
#include "procFunc.h"
#include "writeFunc.h"

int main()
{
    //путь на файл с матрицей и колич
    std::string path = "test.txt";
    //создание матрицы и запись в нее элементов матрицы из файлы, так как матрица квадратная, то столбцы = строки = n
    int n;
    std::vector <std::vector<int>> matrix(1, std::vector<int>(1));
    matrix = readFunc(path);
    n = matrix.size();
    //проверяем подходит ли матрица под условие
    bool result;
    result = isFit(&matrix[0], matrix.size());//использование указателя на первый элемент матрицы(matrix), то есть на первую строку(matrix[0])
    
    
    //создание новой транспонированной матрицы, чтоб провести обработку
    std::vector <std::vector<int>> matrix_tr(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) matrix_tr[i][j]  = matrix[j][i];
    }
    //выполнение программы основываясь на удовлетворении матрицей условий
    if (result) {
        procFunc(&matrix_tr[0], n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) matrix[i][j] = matrix_tr[j][i];
        }
        writeFunc(&matrix[0], n);
        std::cout << "Well done! Check 'ans.txt'." << std::endl;
    }
    else {
        std::cout << "Matrix is wrong";
        return 0;
    }
    return 0;
}

