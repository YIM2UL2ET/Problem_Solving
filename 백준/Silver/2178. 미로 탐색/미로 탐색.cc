#include <iostream>
#include <vector>
#include <queue>

int bfs(std::vector <std::string> maze, int n, int m) {
    int res = 0;
    bool isFind = false;
    std::vector <std::pair <int, int>> offset = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    std::queue <std::pair <int, int>> que;

    que.push({0,0});
    maze[0][0] = '.';
    while (!isFind) {
        res++;
        int cnt = que.size();

        for (int i = 0; i < cnt; i++) {
            if (que.front().first == n-1 && que.front().second == m-1) {
                isFind = true;
                break;
            }

            for (std::pair <int, int> set : offset) {
                int nr = que.front().first + set.first, nc = que.front().second + set.second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && maze[nr][nc] == '1') {
                    maze[nr][nc] = '.';
                    que.push({nr,nc});
                }
            }
            que.pop();
        }
    }
    return res;
}

int main(void) {
    int n, m;
    std::cin >> n >> m;

    std::vector <std::string> maze(n);
    for (int i = 0; i < n; i++) std::cin >> maze[i];
    std::cout << bfs(maze, n, m);
    return 0;
}