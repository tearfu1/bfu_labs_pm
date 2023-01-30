#include <iostream>

int main()
{
    int n;
    std::cout << "Input product code (1-5): ";
    std::cin >> n;
    switch (n) {
    case 1:
        std::cout << "Item with this number is Tomato\n";
        break;
    case 2:
        std::cout << "Item with this number is Avocado\n";
        break;
    case 3:
        std::cout << "Item with this number is Grape\n";
        break;
    case 4:
        std::cout << "Item with this number is fig\n";
        break;
    case 5:
        std::cout << "Item with this number is Watermelon\n";
        break;
    default:
        std::cout << "Invalid input";
        break;
    }
    return 0;
}