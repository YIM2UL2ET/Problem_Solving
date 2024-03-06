#include <iostream>

std::string str[28];

std::string func(int n)
{
    if (str[n].size() < 1) {
        str[n] += func(n-1);
        int three = 1;
        for (int i = 0; i < n-1; i++, three *= 3);
        for (int i = 0; i < three; i++) str[n] += " ";
        str[n] += func(n-1);
    }
    return str[n];
}

int main(void)
{
    str[0] = "-";
    int n;
    std::cin >> n;
    while (!std::cin.eof()) {
        std::cout << func(n) << "\n";
        std::cin >> n;
    }
    return 0;
}