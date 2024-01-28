#include <iostream>

int main(void)
{
    int n, result, red, blue;
    std::string str;

    std::cin >> n;
    std::cin >> str;

    red = 0, blue = 0;
    if (str[0] == 'R') red++;
    else blue++;
    for (int i = 1; i < n; i++) {
        if (str[i-1] != str[i]) {
            if (str[i] == 'R') red++;
            else blue++;
        }
    }

    if (blue > red) result = 1 + red;
    else result = 1 + blue;
    std::cout << result;
    
    return 0;
}