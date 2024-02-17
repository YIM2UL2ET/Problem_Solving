#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    int total = 0;
    std::vector <int> vec(5);
    for (int i = 0; i < 5; i++) {
        std::cin >> vec[i];
        total += vec[i];
    }
    std::sort(vec.begin(), vec.end());
    std::cout << total / 5 << std::endl << vec[2];
    return 0;
}