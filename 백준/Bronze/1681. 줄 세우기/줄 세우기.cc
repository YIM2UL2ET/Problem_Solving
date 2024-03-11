#include <iostream>

int main(void)
{
    int n, l, res;
    std::cin >> n >> l;
    for (res = 1; n > 0; res++) {
        int tmp = res;
        while (tmp > 0) {
            if (tmp % 10 != l) tmp /= 10;
            else break;
        }
        if (tmp == 0) n--;
    }
    std::cout << --res;
    return 0;
}