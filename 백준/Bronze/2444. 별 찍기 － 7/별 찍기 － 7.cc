#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    n--;
    for (int i = -1 * n; i <= n; i++) {
        for (int j = 0; j < abs(i) ; j++) std::cout << " ";
        for (int j = 0; j < (n-abs(i))*2+1; j++) std::cout << "*";
        std::cout << "\n";
    }
    return 0;
}