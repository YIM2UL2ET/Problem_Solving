#include <iostream>

int main(void)
{
    int n, result;
    std::cin >> n;

    int ary[n];
    for (int i = 0; i < n; i++) {
        std::cin >> ary[i];
    }

    result = 0;
    for (int i = n-1; i > 0; i--) {
        if (!(ary[i] > ary[i-1])) {
            int temp = ary[i-1] - ary[i] + 1;
            ary[i-1] -= temp;
            result += temp;
        }
    }
    
    std::cout << result;

    return 0;
}