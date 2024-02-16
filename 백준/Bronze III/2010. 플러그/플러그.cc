#include <iostream>

int main(void)
{
    int n, result = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        result += temp;
    }
    result -= n - 1;
    std::cout << result;
    return 0;
}