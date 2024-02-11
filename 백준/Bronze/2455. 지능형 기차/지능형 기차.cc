#include <iostream>

int main(void)
{
    int result = 0, max = 0;
    int a, b;
    for (int i = 0; i < 4; i++) {
        std::cin >> a >> b;
        result += b - a;
        max = max > result ? max : result;
    }
    std::cout << max;
    return 0;
}