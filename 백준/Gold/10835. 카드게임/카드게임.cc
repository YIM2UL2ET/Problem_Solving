#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<int> leftCard(N);
  vector<int> rightCard(N);
  vector<vector<int>> dp(N + 1, vector<int>(N + 1));

  for (int i = 0; i < N; i++) {
    cin >> leftCard[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> rightCard[i];
  }

  for (int r = 1; r <= N; r++) {
    for (int l = 1; l <= N; l++) {
      dp[l][r] = max(dp[l - 1][r], dp[l - 1][r - 1]);
      if (leftCard[N - l] > rightCard[N - r]) {
        dp[l][r] = max(dp[l][r], dp[l][r - 1] + rightCard[N - r]);
      }
    }
  }

  cout << dp[N][N];

  return 0;
}