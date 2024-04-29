#include <iostream>
#include <queue>
#include <vector>

const std::vector <std::pair <int, int>> offset = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int func1(std::vector <std::vector <int>> &matrix, int r, int c) {
    int rsize = matrix.size(), csize = matrix[0].size();
    int res = matrix[r][c], minValue = 1001;

    for (auto set : offset) {
        int nr = set.first + r, nc = set.second + c;
        if (nr >= 0 && nr < rsize && nc >= 0 && nc < csize) {
            res += matrix[nr][nc], minValue = minValue < matrix[nr][nc] ? minValue : matrix[nr][nc];
        }
        else minValue = 0;
    }
    return res - minValue;
}

int func2(std::vector <std::vector <int>> &matrix, int r, int c, int level) {
    if (level == 1) return matrix[r][c];

    int rsize = matrix.size(), csize = matrix[0].size();
    int res = matrix[r][c], maxValue = 0;
    int temp = matrix[r][c];

    matrix[r][c] = 0;
    for (auto set : offset) {
        int nr = set.first + r, nc = set.second + c;
        if (nr >= 0 && nr < rsize && nc >= 0 && nc < csize && matrix[nr][nc] > 0) {
            int v = func2(matrix, nr, nc, level-1);
            maxValue = maxValue > v ? maxValue : v;
        }
    }
    matrix[r][c] = temp;
    return res + maxValue;
}

int main(void) {
    int n, m, res = 0;
    std::cin >> n >> m;

    std::vector <std::vector <int>> matrix(n, std::vector <int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int v1 = func1(matrix, i, j);
            int v2 = func2(matrix, i, j, 4);
            if (res < v1 || res < v2) res = v1 > v2 ? v1 : v2;
        }
    }
    
    std::cout << res;
    return 0;
}