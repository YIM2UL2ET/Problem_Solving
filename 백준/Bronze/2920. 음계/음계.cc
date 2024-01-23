#include <iostream>

int main(void)
{
    int i;
    int ary[8];
    for (i = 0; i < 8; i++) {
        std::cin >> ary[i];
    }
    
    for (i = 0; i < 8; i++) {
        if (ary[i] != i+1) break;
    }
    if (i == 8) {
        std::cout << "ascending";
        return 0;
    }

    for (i = 0; i < 8; i++) {
        if (ary[i] != 8-i) break;
    }
    if (i == 8) {
        std::cout << "descending";
        return 0;
    }

    std::cout << "mixed";
    return 0;
}