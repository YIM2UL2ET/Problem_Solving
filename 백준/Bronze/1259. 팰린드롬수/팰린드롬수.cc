#include <iostream>

int main(void)
{
    std::string n;
    std::cin >> n;
    while (n != "0") {
        int cnt;
        for (cnt = 0; cnt < n.size()/2; cnt++) {
            if (n[cnt] != n[n.size()-1-cnt]) break;
        }
        if (cnt == n.size()/2) std::cout << "yes\n";
        else std::cout << "no\n";
        std::cin >> n;
    }
    return 0;
}