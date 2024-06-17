#include <iostream>
#include <vector>
using namespace std;

static int N, M, K;
vector<vector<int>> matrix;
vector<pair<int, int>> offset{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int r, int c) {
  int value = matrix[r][c];
  matrix[r][c] = 0;
  for (auto &set : offset) {
    int newR = r + set.first;
    int newC = c + set.second;

    if (newR >= 0 && newR < N && newC >= 0 && newC < M &&
        matrix[newR][newC] > 0 && abs(value - matrix[newR][newC]) <= K) {
      dfs(newR, newC);
    }
  }
}

int main() {
  int ans;
  cin >> N >> M >> K;

  matrix.resize(N, vector<int>(M));
  for (auto &row : matrix) {
    for (int &element : row) {
      cin >> element;
    }
  }

  ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (matrix[i][j] > 0) {
        ans++;
        dfs(i, j);
      }
    }
  }

  cout << ans;

  return 0;
}