#include <iostream>

int main(void)
{
    int a;
    std::cin >> a;

    for (int i = 1; i <= a; i++) {
        if (30 % (i+1) == 0) std::cout << i << "\n";
    }
    return 0;
}