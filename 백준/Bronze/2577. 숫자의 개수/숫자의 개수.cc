#include <iostream>

int main(void)
{
    int a, b, c, total;
    int ary[10] = {};
    std::cin >> a >> b >> c;
    total = a * b * c;
    while (total > 0) {
        ary[total % 10]++;
        total /= 10;
    }
    for (int i = 0; i < 10; i++) {
        std::cout << ary[i] << std::endl;
    }
    return 0;
}