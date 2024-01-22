#include <iostream>

int main(void)
{
    int cnt;
    std::cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int h, w, n, rh, rw;
        std::cin >> h >> w >> n;
        rh = n % h, rw = (n / h) + 1;

        if (rh == 0) {
            std::cout << h;
            rw--;
        }
        else std::cout << rh;

        if (rw < 10) std::cout << '0';
        std::cout << rw << std::endl;
    }
    return 0;
}