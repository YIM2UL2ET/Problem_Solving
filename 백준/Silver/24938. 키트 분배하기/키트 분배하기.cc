#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    int array[n];
    long long avg = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
        avg += array[i];
    }
    avg /= n;

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] > avg) {
            result += array[i] - avg;
            array[i+1] += array[i] - avg;
        }
        else if (array[i] < avg) {
            result += avg - array[i];
            array[i+1] -= avg - array[i];
        }
        array[i] = avg;
    }
    
    std::cout << result;
    return 0;
}