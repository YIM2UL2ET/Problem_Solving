#include <iostream>

int main(void)
{
    long long a, b, n;
    std::cin >> a >> b;
    n = a - b;
    if (n < 0) n *= -1;
    std::cout << n;
    return 0;
}