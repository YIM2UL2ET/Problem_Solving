#include <iostream>

int main(void)
{
    int n, result = 0, mul = 0;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        int temp = 0;
        std::cin >> array[i];

        while (array[i] > 0) {
            if (array[i] % 2 == 0) {
                array[i] /= 2;
                temp++;
            }
            else {
                array[i]--;
                result++;
            }
        }
        if (mul < temp) mul = temp;
    }
    result += mul;
    std::cout << result;
    return 0;
}