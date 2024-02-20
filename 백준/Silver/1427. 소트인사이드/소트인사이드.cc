#include <iostream>
#include <algorithm>

int main(void)
{
    std::string str;
    std::cin >> str;
    std::sort(str.rbegin(), str.rend());
    std::cout << str;
    return 0;
}