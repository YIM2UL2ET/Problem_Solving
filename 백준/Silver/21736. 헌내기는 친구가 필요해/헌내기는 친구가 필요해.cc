#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

int bfs(std::vector <std::string> matrix, int n, int m, int y, int x) {
    int res = 0;
    std::queue <std::pair <int, int>> que;
    std::vector <std::pair <int, int>> offset = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    que.push({y, x});
    matrix[y][x] = 'X';

    while (!que.empty()) {
        for (auto set : offset) {
            int ny = que.front().first + set.first, nx = que.front().second + set.second;
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && matrix[ny][nx] != 'X') {
                if (matrix[ny][nx] == 'P') res++;
                matrix[ny][nx] = 'X';
                que.push({ny, nx});
            }
        }
        que.pop();
    }
    return res;
}

int main(void)
{
    int n, m, py, px, res;
    std::cin >> n >> m;

    std::vector <std::string> matrix(n);
    for (int i = 0; i < n; i++) {
        std::cin >> matrix[i];
        auto it = std::find(matrix[i].begin(), matrix[i].end(), 'I');
        if (it != matrix[i].end()) py = i, px = it-matrix[i].begin(); 
    }

    res = bfs(matrix, n, m, py, px);
    if (res == 0) std::cout << "TT";
    else std::cout << res;
    return 0;
}