#include <iostream>

int main(void)
{
    int e, s, m, result;
    std::cin >> e >> s >> m;

    while (e != s || s != m || e != m) {
        if (e <= s && e <= m) e += 15;
        else if (s <= e && s <= m) s += 28;
        else if (m <= e && m <= s) m += 19;    
    }
    
    std::cout << e;
    return 0;
}