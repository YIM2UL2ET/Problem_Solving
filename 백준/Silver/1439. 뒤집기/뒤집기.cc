#include <iostream>

int main(void)
{
    std::string str;
    std::cin >> str;
    const int len = str.size();
    int zero = 0, one = 0;

    
    if (str[0] == '0') zero++;
    else one++;

    for (int i = 1; i < len; i++) {
        if (str[i] != str[i-1]) {
            if (str[i] == '0') zero++;
            else one++;
        }
    }

    if (zero > one) std::cout << one;
    else std::cout << zero;

    return 0; 
}