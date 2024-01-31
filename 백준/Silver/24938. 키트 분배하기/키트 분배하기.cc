#include <iostream>

int main(void)
{
    int n, temp, avg;
    std::cin >> n;
    int array[n];

    avg = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
        temp += array[i];
        avg += temp / n;
        temp %= n;
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += abs(array[i] - avg);
        array[i+1] += array[i] - avg;
        array[i] = avg;
    }
    
    std::cout << result;
    return 0;
}