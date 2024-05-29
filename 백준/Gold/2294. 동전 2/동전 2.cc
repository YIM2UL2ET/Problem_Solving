#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;

  vector<int> coins(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> coins[i];
  }

  vector<vector<int>> dp(N + 1, vector<int>(K + 1, INT16_MAX));
  dp[0][0] = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= K; j++) {
      if (j >= coins[i]) {
        dp[i][j] = min(dp[i][j - coins[i]] + 1, dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  if (dp[N][K] == INT16_MAX) {
    cout << -1;
  } else {
    cout << dp[N][K];
  }

  return 0;
}