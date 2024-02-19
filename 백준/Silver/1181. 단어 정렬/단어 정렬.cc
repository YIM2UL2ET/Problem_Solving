#include <iostream>
#include <algorithm>

bool cmp(std::string str1, std::string str2)
{
    if (str1.size() == str2.size()) return str1 < str2;
    else return str1.size() < str2.size();
}

int main(void)
{
    int n;
    std::cin >> n;

    std::string str[n]; 
    for (int i = 0; i < n; i++) {
        std::cin >> str[i];
    }

    std::sort(str, str+n, cmp);

    for (int i = 0; i < n; i++) {
        if (i != 0 && str[i-1] == str[i]) continue;
        else std::cout << str[i] << std::endl;
    }
    
    return 0;
}