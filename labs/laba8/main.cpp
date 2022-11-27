#include <iostream>

int main() {
    unsigned long long a = 123;//определение числа
    for (int i = 0; i < sizeof(a); ++i)std::cout << *(((bool*)(&a))+i) << std::endl;
    //берем адрес &a(он указывает на первый байт числа), далее переопределяем этот адрес, как bool*, чтоб можно было двигаться по 1 байту, так как bool занимает 1 байт, а long long 8, и разыменовываем
}
