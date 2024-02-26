#include <iostream>
#include <algorithm>

bool cmp(std::string str1, std::string str2)
{
    if (str1.size() != str2.size()) return str1.size() < str2.size();
    else {
        int sn1 = 0, sn2 = 0;
        for (int i = 0; i < str1.size(); i++) {
            if (isdigit(str1[i])) sn1 += str1[i] - 48;
            if (isdigit(str2[i])) sn2 += str2[i] - 48;
        }
        if (sn1 != sn2) return sn1 < sn2;
        else return str1 < str2;
    }
}

int main(void)
{
    int n;
    std::cin >> n;

    std::string str[n];
    for (int i = 0; i < n; i++) std::cin >> str[i];

    std::sort(str, str+n, cmp);
    for (int i = 0; i < n; i++) std::cout << str[i] << std::endl;
    return 0;
}