#include <iostream>
#include <queue>
#include <vector>

std::vector <std::vector <int>> bfs(std::vector <std::vector <char>> matrix, int n, int m, int r, int c) {
    int cnt = 0;
    std::vector <std::vector <int>> res(n, std::vector <int>(m));
    std::queue <std::pair <int, int>> que;
    std::vector <std::pair <int, int>> offset = {{1,0},{-1,0},{0,1},{0,-1}};

    que.push({r,c});
    while (!que.empty()) {
        cnt++;
        int size = que.size();
        for (int i = 0; i < size; i++) {
            for (auto set : offset) {
                int nr = set.first + que.front().first, nc = set.second + que.front().second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && matrix[nr][nc] == '1') {
                    matrix[nr][nc] = '.', res[nr][nc] = cnt, que.push({nr,nc});
                }
            }
            que.pop();
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1') res[i][j] = -1;
        }
    }

    return res;
}

int main(void) {
    int n, m, nr, nc;
    std::cin >> n >> m;

    std::vector <std::vector <char>> matrix(n, std::vector <char>(m));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            std::cin >> matrix[r][c];
            if (matrix[r][c] == '2') nr = r, nc = c;
        }
    }
    
    std::vector <std::vector <int>> res = bfs(matrix, n, m, nr, nc);

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            std::cout << res[r][c] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}