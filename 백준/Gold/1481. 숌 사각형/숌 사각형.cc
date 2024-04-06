#include <iostream>
#include <vector>

bool solve (std::vector <std::vector <int>>& matrix, int r, int c, int lv) {
    std::vector <int> digits;
    for (int i = 0; i < lv; i++) digits.push_back(i);

    for (int i = 0; i < r; i++) digits[matrix[i][c]] = -1;
    for (int i = 0; i < c; i++) digits[matrix[r][i]] = -1;

    for (int item : digits) {
        if (item > -1) {
            matrix[r][c] = item;
            if (c+1 == lv || solve(matrix, r, c+1, lv)) return true;
        }
    }
    return false;
}

void print(std::vector <std::vector <int>>& matrix, int n, int d) {
    for (int i = 0; i < n-d; i++) {
        for (int j = 0; j < n-d; j++) std::cout << matrix[0][0] << ' ';
        for (int item : matrix[0]) std::cout << item << ' ';
        std::cout << '\n';
    }
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n-d; j++) std::cout << matrix[i][0] << ' ';
        for (int item : matrix[i]) std::cout << item << ' ';
        std::cout << '\n';
    }
}

int main(void) {
    int n, d;
    std::cin >> n >> d;
    
    std::vector <std::vector <int>> matrix(d, std::vector <int> (d));
    for (int i = 0; i < d; i++) matrix[0][i] = i;
    for (int r = 1; r < d; r++) solve(matrix, r, 0, d);
    
    print(matrix, n, d);
    return 0;
}