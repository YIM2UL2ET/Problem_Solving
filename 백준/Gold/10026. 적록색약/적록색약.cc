#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

void bfs(std::vector <std::string> &matrix, int y, int x, char ch) {
    int size = matrix.size();
    std::queue <std::pair <int, int>> que;
    std::vector <std::pair <int, int>> offset = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    que.push({y, x});
    matrix[y][x] = '.';
    while (!que.empty()) {
        for (std::pair <int, int> set : offset) {
            int ny = que.front().first + set.first, nx = que.front().second + set.second;
            if (ny >= 0 && ny < size && nx >= 0 && nx < size && matrix[ny][nx] == ch) {
                que.push({ny, nx});
                matrix[ny][nx] = '.';
            }
        }
        que.pop();
    }
    return;
}

int main(void)
{
    int n, res1 = 0, res2 = 0;
    std::string buffer;
    std::vector <std::string> 
    matrix1;
    std::vector <std::string> matrix2;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> buffer;
        matrix1.push_back(buffer);
        std::replace(buffer.begin(), buffer.end(), 'G', 'R');
        matrix2.push_back(buffer);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix1[i][j] != '.') {
                bfs(matrix1, i, j, matrix1[i][j]), res1++;
            }
            if (matrix2[i][j] != '.') {
                bfs(matrix2, i, j, matrix2[i][j]), res2++;
            }
        }
    }

    std::cout << res1 << ' ' << res2;
    return 0;
}