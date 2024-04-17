#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class point {
public:
    int row, col;
    point(int r, int c): row(r), col(c) {}
};

int bfs(vector <vector <int>> &matrix, vector <point> &virus, int n, int m) {
    int res = 0;
    queue <point> que;
    vector <point> offset = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    for (auto p : virus) que.push(p);

    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            for (auto set : offset) {
                int nr = set.row + que.front().row, nc = set.col + que.front().col;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !matrix[nr][nc]) {
                    que.push({nr,nc});
                    matrix[nr][nc] = 2;
                }
            }
            que.pop();
        }
    }

    for (auto row : matrix) {
        for (auto box : row) {
            if (!box) res++;
        }
    }
    return res;
}

int bruteForce(vector <vector <int>> &matrix, vector <point> &virus, vector <point> &ground, int n, int m) {
    int cnt = ground.size();
    int res = 0;
    for (int i = 0; i < cnt; i++) {
        for (int j = i+1; j < cnt; j++) {
            for (int k = j+1; k < cnt; k++) {
                auto tmp = matrix;
                tmp[ground[i].row][ground[i].col] = 1;
                tmp[ground[j].row][ground[j].col] = 1;
                tmp[ground[k].row][ground[k].col] = 1;
                int t = bfs(tmp, virus, n, m);
                res = res > t ? res : t;
            }
        }
    }
    return res;
}

int main(void) {
    int n, m;
    vector <point> virus;
    vector <point> ground;

    cin >> n >> m;

    vector <vector <int>> matrix(n, vector <int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 2) virus.push_back({i,j});
            else if (matrix[i][j] == 0) ground.push_back({i,j});
        }
    }
    
    cout << bruteForce(matrix, virus, ground, n, m);
    return 0;
}