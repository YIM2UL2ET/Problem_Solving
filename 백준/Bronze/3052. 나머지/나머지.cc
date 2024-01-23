#include <iostream>

int main(void)
{
    int ary[10] = {'\0'};
    int i, j, n, result = 0;
    for (i = 0; i < 10; i++) {
        std::cin >> n;
        n %= 42;

        for (j = 0; j < result; j++) {
            if (ary[j] == n) break;
        }

        if (j == result) {
            ary[j] = n;
            result ++;
        }
    }
    std::cout << result;
    return 0;
}