#include <iostream>
#include <set>
#include <vector>
using namespace std;

int N;
vector<vector<vector<int>>> dp;
vector<vector<char>> matrix;

int func(int endR, int endC, int type) {
  if (dp[endR][endC][type] == -1) {
    bool isTrans = false, isLen = false;
    dp[endR][endC][type] = 0;

    if (endR + 1 >= 0 && endR + 1 < N && matrix[endR + 1][endC] == '0') {
      if (type != 2) dp[endR][endC][type] += func(endR + 1, endC, 0);
      isTrans = true;
    }
    if (endC + 1 >= 0 && endC + 1 < N && matrix[endR][endC + 1] == '0') {
      if (type != 0) dp[endR][endC][type] += func(endR, endC + 1, 2);
      isLen = true;
    }
    if (isTrans && isLen && matrix[endR + 1][endC + 1] == '0') {
      dp[endR][endC][type] += func(endR + 1, endC + 1, 1);
    }
  }
  return dp[endR][endC][type];
}

int main(void) {
  cin >> N;
  matrix.resize(N, vector<char> (N));
  dp.resize(N, vector<vector<int>>(N, vector<int>(3, -1)));
  dp.back().back() = {1, 1, 1};

  int p;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      cin >> matrix[r][c];
    }
  }

  cout << func(0, 1, 2);
  return 0;
}