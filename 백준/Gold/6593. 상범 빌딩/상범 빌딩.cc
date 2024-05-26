#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct idx {
  int l, r, c;
};

vector<idx> offset{{0, 0, 1},  {0, 0, -1}, {0, 1, 0},
                   {0, -1, 0}, {1, 0, 0},  {-1, 0, 0}};

int bfs(vector<vector<vector<char>>> &cube, idx start, idx size) {
  int ans = 0;
  queue<idx> que;

  que.push(start);
  cube[start.l][start.r][start.c] = '#';

  while (!que.empty()) {
    ans++;
    int cnt = que.size();

    for (int t = 0; t < cnt; t++) {
      for (auto set : offset) {
        int l = que.front().l + set.l;
        int r = que.front().r + set.r;
        int c = que.front().c + set.c;

        if (l >= 0 && l < size.l && r >= 0 && r < size.r && c >= 0 &&
            c < size.c && cube[l][r][c] != '#') {
          if (cube[l][r][c] == 'E') {
            return ans;
          } else {
            cube[l][r][c] = '#';
            que.push({l, r, c});
          }
        }
      }

      que.pop();
    }
  }

  return 0;
}

int solve(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int L, R, C;
  idx start;
  cin >> L >> R >> C;

  if (L == 0 && R == 0 && C == 0) return -1;

  vector<vector<vector<char>>> cube(L,
                                    vector<vector<char>>(R, vector<char>(C)));
  for (int l = 0; l < L; l++) {
    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        cin >> cube[l][r][c];
        if (cube[l][r][c] == 'S') start = {l, r, c};
      }
    }
  }

  return bfs(cube, start, {L, R, C});
}

int main(void) {
  int ans = solve();
  while (ans >= 0) {
    if (ans == 0)
      cout << "Trapped!\n";
    else
      cout << "Escaped in " << ans << " minute(s).\n";

    ans = solve();
  }
  return 0;
}