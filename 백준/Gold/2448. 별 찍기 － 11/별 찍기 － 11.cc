#include <iostream>
#include <vector>

void func(std::vector <std::string> &matrix, int r, int c, int lv) {
    if (lv == 1) {
        matrix[r][c-1] = '*', matrix[r][c-2] = '*', matrix[r-1][c-1] = '*', matrix[r-1][c+1] = '*';
        matrix[r][c] = '*', matrix[r][c+1] = '*', matrix[r][c+2] = '*', matrix[r-2][c] = '*';
    }
    else {
        func(matrix, r-lv, c, lv/2);
        func(matrix, r, c-lv, lv/2);
        func(matrix, r, c+lv, lv/2);
    }
    return;
}

int main(void) {
    int n;
    std::cin >> n;
    std::vector <std::string> matrix (n, std::string(n*2-1,' '));

    func(matrix, n-1, n-1, n/2);
    for (std::string str : matrix) std::cout << str << '\n';
    return 0;
}