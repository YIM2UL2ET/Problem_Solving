#include <iostream>
#include <algorithm>

int main(void)
{
    std::string a, b;
    std::cin >> a >> b;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) {
            std::cout << a;
            break;
        }
        else if (a[i] < b[i]) {
            std::cout << b;
            break;
        }
    }
    return 0;
}