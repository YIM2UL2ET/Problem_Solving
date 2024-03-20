#include <iostream>

int main(void)
{
    int n, a, b, i;
    std::cin >> n >> a >> b;
    i = a / 2 + b;
    if (n > i) std::cout << i;
    else std::cout << n;
    return 0;
}