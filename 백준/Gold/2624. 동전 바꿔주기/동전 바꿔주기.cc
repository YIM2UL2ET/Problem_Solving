#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int N, T;
  cin >> T >> N;

  vector<int> coins(N + 1);
  vector<int> numOfCoin(N + 1);
  vector<vector<int>> dp(N + 1, vector<int>(T + 1, 0));

  for (int i = 1; i <= N; i++) {
    cin >> coins[i] >> numOfCoin[i];
  }

  dp[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= T; j++) {
      for (int k = 0; k <= numOfCoin[i]; k++) {
        if (j - coins[i] * k >= 0) {
          dp[i][j] += dp[i-1][j - coins[i] * k];
        }
      }
    }
  }
  
  cout << dp[N][T];

  return 0;
}