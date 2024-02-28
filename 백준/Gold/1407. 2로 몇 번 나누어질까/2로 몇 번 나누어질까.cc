#include <iostream>

int main(void)
{
    long long answer, distance, a, b;
    std::cin >> a >> b;

    answer = 0, distance = 1;
    for (int i = 0; distance <= b; i++) {
        distance *= 2;
        answer += ((b + distance/2) / distance - (a-1 + distance/2) / distance )* distance / 2;
    }
    
    std::cout << answer;
    return 0;
}