#include <iostream>

int FindMax(std::string str);
int FindMin(std::string str);

int main(void)
{
    int min, max;
    std::string a, b;
    std::cin >> a >> b;
    
    min = FindMin(a) + FindMin(b);
    max = FindMax(a) + FindMax(b);

    std::cout << min << " " << max;
    return 0;   
}

int FindMax(std::string str)
{
    int result = 0;
    for (int i = 0; i < str.size(); i++) {
        result *= 10;
        if (str[i] == '5') result += 6;
        else result += str[i] - 48;
    }
    return result;
}

int FindMin(std::string str)
{
    int result = 0;
    for (int i = 0; i < str.size(); i++) {
        result *= 10;
        if (str[i] == '6') result += 5;
        else result += str[i] - 48;
    }
    return result;
}