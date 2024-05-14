#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int N, W;
  cin >> N >> W;

  vector<int> weight(N + 1);
  vector<int> price(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> weight[i] >> price[i];
  }

  vector<vector<int>> dp(N + 1, vector<int>(W + 1));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= W; j++) {
      if (weight[i] <= j) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + price[i]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[N][W];

  return 0;
}