#include <iostream>
#include <cctype>

int main(void)
{
    std::string str;
    std::cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (isupper(str[i])) str[i] = tolower(str[i]);
        else str[i] = toupper(str[i]); 
    }
    std::cout << str;
    return 0;
}