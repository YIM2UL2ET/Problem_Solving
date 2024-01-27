#include <iostream>

int main(void)
{
    char grade[3];
    double result = 0;

    std::cin >> grade;
    result += 69 - grade[0];

    if (result == -1) std::cout << "0.0";
    else {
        if (grade[1] == '+') result += 0.3;
        else if (grade[1] == '-') result -= 0.3;

        std::cout << std::fixed;
        std::cout.precision(1);
        std::cout << result;
    }

    return 0;
}