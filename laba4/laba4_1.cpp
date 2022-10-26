#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#include <stdio.h> 

//просто вывод
void before(std::vector <int> a, int n) {
    std::cout << "Subsequence before:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

//функция вывода относительно результата
void result(bool flag, int wr_num, std::vector <int> a, int n) {
    if (flag) {
        sort(a.begin(), a.end());
        std::cout << "Due to no numbers with sum of digits equal to 19 the subsequence:\n";
        for (int i = n - 1; i >= 0; --i) {
            std::cout << a[i] << " ";
        }
    }
    else {
        std::cout << "Due to number(s) with sum of digits equal to 19 the subsequence doesn't change:\n";
        for (int i = 0; i < n; ++i) {
            std::cout << a[i] << " ";
        }
        std::cout << "\n" << "This number: " << wr_num;

    }
}

int main()
{
    //All
    bool flag = true;
    int wr_num = 0;
    std::string user_choise = "";
    std::cout << "Auto or Manual?: ";
    std::cin >> user_choise;
    
   
    if (user_choise == "Auto") {
        int n;
        srand(time(NULL));
        n = rand() % 10 + 2;
        std::vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            int temp_sum = 0;
            int t = rand() % 10000 + 1;
            a[i] = t;
            while (t > 0) {
                temp_sum += t % 10;
                t /= 10;
            }
            if (flag) {
                flag = (temp_sum != 19) * flag;
            }
            if (wr_num == 0 && flag == 0) {
                wr_num = a[i];
            }
        }
        before(a, n);
        result(flag, wr_num, a, n);
    }
    else if (user_choise == "Manual") {
        int k = 0;
        std::cout << "Input Length of subsequence: ";
        std::cin >> k;
        std::vector <int> b(k);
        for (int i = 0; i < k; ++i) {
            int temp_sum = 0;
            int t;
            std::cout << "Input a number: ";
            std::cin >> t;
            b[i] = t;
            while (t > 0) {
                temp_sum += t % 10;
                t /= 10;
            }
            if (flag) {
                flag = (temp_sum != 19) * flag;
            }
            if (wr_num == 0 && flag == 0) {
                wr_num = b[i];
            }
        }
        before(b, k);
        result(flag, wr_num, b, k);
    }
    else {
        std::cout << "Invalid input";
    }
   
    return 0;
}