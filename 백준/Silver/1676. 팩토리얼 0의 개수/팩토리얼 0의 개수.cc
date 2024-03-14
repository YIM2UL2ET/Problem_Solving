#include <iostream>

int main(void)
{
    int n, res, fac;
    std::cin >> n;

    fac = 1, res = 0;
    for (int i = 1; i <= n; i++) {
        fac *= i;
        while (fac % 10 == 0) fac /= 10, res++;
        fac %= 1000000;
    }
    std::cout << res;
    return 0;
}