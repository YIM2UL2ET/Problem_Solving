#include <iostream>
#include <vector>

void func(std::vector <std::string> &matrix, int r, int c, int lv) {
    if (lv == 0) matrix[r][c] = '*';
    else {
        func(matrix, r-lv, c-lv, lv/3); func(matrix, r-lv, c, lv/3); func(matrix, r-lv, c+lv, lv/3);
        func(matrix, r, c-lv, lv/3); func(matrix, r, c+lv, lv/3);
        func(matrix, r+lv, c-lv, lv/3); func(matrix, r+lv, c, lv/3); func(matrix, r+lv, c+lv, lv/3);
    }
    return;
}

int main(void) {
    int n;
    std::cin >> n;
    std::vector <std::string> matrix (n, std::string(n,' '));

    func(matrix, n/2, n/2, n/3);
    for (std::string str : matrix) std::cout << str << '\n';
    return 0;
}