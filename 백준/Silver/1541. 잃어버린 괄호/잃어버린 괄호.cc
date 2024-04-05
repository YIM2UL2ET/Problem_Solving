#include <iostream>
#include <sstream>

int main(void) {
    int res = 0, v;
    char op;
    bool c = false;
    std::string str;
    std::stringstream ss;

    std::cin >> str;
    ss.str(str), ss >> op;
    if (op == '-') c = true;
    else ss.unget();

    while (ss >> v >> op) {
        if (c) res -= v;
        else res += v;

        if (op == '-') c = true;
    }
    if (c) res -= v;
    else res += v;

    std::cout << res;
    return 0;
}