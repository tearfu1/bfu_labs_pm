#include <iostream>
//вывод содержимого байтов
void bit_out(unsigned char* p) {
    int i = 128;
    while (true) {
        if (*p & i) {
            std::cout << "1";
        }
        else {
            std::cout << "0";
        }
        if (i == 1) {
            std::cout << std::endl;
            break;
        }
        i >>= 1;
    }
}
//вывод всей последовательности
void num_out(unsigned char* p) {
    for (int k = 0; k < 8; ++k) {
        unsigned char ans = 0;
        int l = 0;
        l = 0 * (k == 0) + 5 * (k == 1) + 2 * (k == 2) + 7 * (k == 3) + 4 * (k == 4) + 1 * (k == 5) + 6 * (k == 6) + 3 * (k == 7);
        int ls = l;
        int n = 0;
        n = 0 * (k == 0) + 0 * (k == 1) + 1 * (k == 2) + 1 * (k == 3) + 2 * (k == 4) + 3 * (k == 5) + 3 * (k == 6) + 4 * (k == 7);
        for (int j = 0; j < 5;++j) {
            unsigned char temp = *(p+n);
            if (l < 8) {
                ans |= ((1 << l) & temp) >> ls;
            }
            else {
                temp = *(p + n+1);
                ans |= ((1 << (l - 8)) & temp) << (8-ls);
            }
            ++l;
        }
        std::cout << (int)ans << std::endl;
    }
}
//запись битов в байты
void bit_add(unsigned char* p, int* a, int k) {
    int l = 0;
    l = 0 * (k == 0) + 5 * (k == 1) + 2 * (k == 2) + 7 * (k == 3) + 4 * (k == 4) + 1 * (k == 5) + 6 * (k == 6) + 3 * (k == 7);
    int n = 0;
    n = 0 * (k == 0) + 0 * (k == 1) + 1 * (k == 2) + 1 * (k == 3) + 2 * (k == 4) + 3 * (k == 5) + 3 * (k == 6) + 4 * (k == 7);
    while (*a > 0) {
        unsigned char temp = 1 & *a;
        if (l < 8) {
            temp <<= l;
            *(p+n) |= (1 << l) & temp;
        }
        else {
            temp <<= l-8;
            *(p + n + 1) |= (1 << (l-8)) & temp;
        }
        ++l;
        *a >>= 1;
    }
}

//запись чисел и их вывод
int main() {
    unsigned char m[5]{ 0,0,0,0,0 };
    unsigned char* p = m;
    for (int i = 0; i < 8; ++i) {
        int a;
        std::cin >> a;
        bit_add(p, &a, i);
    }
    for (int i = 0; i < 5; ++i) {
        bit_out(p + i);
    }
    num_out(p);
    return 0;
}