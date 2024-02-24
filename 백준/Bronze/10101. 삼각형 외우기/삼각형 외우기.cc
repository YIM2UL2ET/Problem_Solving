#include <iostream>

int main(void)
{
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a + b + c != 180) std::cout << "Error";
    else if (a == 60 && b == 60 && c == 60) std::cout << "Equilateral";
    else if (a == b || b == c || a == c) std::cout << "Isosceles";
    else std::cout << "Scalene";
    return 0;
}