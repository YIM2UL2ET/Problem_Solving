#include <iostream>

int main(void)
{
    int target, temp, n, result;
    std::cin >> temp >> target >> n;

    result = abs(target - temp);
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        result = result < abs(target - temp) + 1 ? result : abs(target - temp) + 1;
    }
    
    std::cout << result;
    return 0;
}