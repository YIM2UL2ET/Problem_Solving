#include <iostream>
#include <algorithm>

int main(void)
{
    std::string str;
    std::cin >> str;
    int n = str.size();
    int res = INT32_MAX;
    int digit = std::count(str.begin(), str.end(), 'a');

    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = i; j < i+digit; j++) {
            if (str[j%n] == 'b') k++;
        }
        if (res > k) res = k;
    }

    std::cout << res;
    return 0;
}