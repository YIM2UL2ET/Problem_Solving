#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct point {int r, c;};

int n, m;
vector <point> offset = {{1,0},{-1,0},{0,1},{0,-1}};

bool corner(vector <vector <char>> &matrix, int r, int c) {
    int cnt = 0;
    for (auto set : offset) {
        int nr = r + set.r, nc = c + set.c;
        if (nr < n && nr >= 0 && nc < m && nc >= 0 && matrix[nr][nc] == '.') cnt++;
    }
    return cnt > 1;
}

bool delCheese(vector <vector <char>> &matrix) {
    bool res = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(matrix[i][j] == '1' && corner(matrix, i, j)) {
                res = true, matrix[i][j] = '0';
            }
        }
    }
    return res;
}

void bfs(vector <vector <char>> &matrix, int r, int c) {
    queue <point> que;
    que.push({r,c});
    while (!que.empty()) {
        for (auto set : offset) {
            int nr = set.r + que.front().r, nc = set.c + que.front().c;
            if (nr < n && nr >= 0 && nc < m && nc >= 0 && matrix[nr][nc] == '0') {
                matrix[nr][nc] = '.', que.push({nr, nc});
            }
        }
        que.pop();
    }
}

void airBFS(vector <vector <char>> &matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.') bfs(matrix, i, j);
        }
    } 
}

int main(void) {
    int res = 0;
    cin >> n >> m;

    vector <vector <char>> matrix(n, vector <char>(m));
    for (auto &row : matrix) {
        for (auto &item : row) cin >> item;
    }

    matrix[0][0] = '.';
    airBFS(matrix);
    while(delCheese(matrix)) res++, airBFS(matrix);
    cout << res;
    return 0;
}