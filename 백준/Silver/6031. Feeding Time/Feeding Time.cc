#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int bfs(vector<vector<char>> &matrix, int mr, int mc) {
  int count = 0;
  int W = matrix.front().size();
  int H = matrix.size();
  queue<pair<int, int>> que;

  matrix[mr][mc] = '*';
  que.push({mr, mc});

  while (!que.empty()) {
    count++;
    int r = que.front().first;
    int c = que.front().second;

    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        int nr = r + i;
        int nc = c + j;

        if (nr >= 0 && nr < H && nc >= 0 && nc < W) {
          if (matrix[r + i][c + j] == '.') {
            que.push({r + i, c + j});
            matrix[r + i][c + j] = '*';
          }
        }
      }
    }

    que.pop();
  }

  return count;
}

int main(void) {
  int W, H, result;

  cin >> W >> H;
  vector<vector<char>> matrix(H, vector<char>(W));
  for (auto &row : matrix) {
    for (auto &item : row) {
      cin >> item;
    }
  }

  result = 0;
  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      if (matrix[r][c] == '.') {
        int temp = bfs(matrix, r, c);
        if (temp > result) {
          result = temp;
        }
      }
    }
  }

  cout << result;
  return 0;
}