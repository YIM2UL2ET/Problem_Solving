#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> offset{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool humanBFS(vector<vector<char>> &matrix, queue<pair<int, int>> &pos, int W, int H) {
  int size = pos.size();
  for (int cnt = 0; cnt < size; cnt++) {
    int r = pos.front().first;
    int c = pos.front().second;
    pos.pop();

    if (matrix[r][c] != '@') continue;

    for (auto set : offset) {
      int nr = r + set.first, nc = c + set.second;
      if (nr < 0 || nr >= H || nc < 0 || nc >= W) {
        return true;
      } else if (matrix[nr][nc] == '.') {
        matrix[nr][nc] = '@';
        pos.push({nr, nc});
      }
    }
  }

  return false;
}

void fireBFS(vector<vector<char>> &matrix, queue<pair<int, int>> &pos, int W, int H) {
  int size = pos.size();
  for (int cnt = 0; cnt < size; cnt++) {
    int r = pos.front().first;
    int c = pos.front().second;
    pos.pop();

    for (auto set : offset) {
      int nr = r + set.first, nc = c + set.second;
      if (nr >= 0 && nr < H && nc >= 0 && nc < W && matrix[nr][nc] != '#') {
        matrix[nr][nc] = '#';
        pos.push({nr,nc});
      }
    }
  }
}

void solve(void) {
  int W, H;
  queue<pair<int, int>> human;
  queue<pair<int, int>> fire;

  cin >> W >> H;

  vector<vector<char>> matrix(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> matrix[i][j];

      if (matrix[i][j] == '@') {
        human.push({i, j});
      } else if (matrix[i][j] == '*') {
        fire.push({i, j});
      }
    }
  }

  int ans = 0;
  while (human.size() > 0) {
    ans++;
    if (humanBFS(matrix, human, W, H)) {
      cout << ans << '\n';
      return;
    } else {
      fireBFS(matrix, fire, W, H);
    }
  }
  
  cout << "IMPOSSIBLE\n";
}

int main(void) {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    solve();
  }

  return 0;
}