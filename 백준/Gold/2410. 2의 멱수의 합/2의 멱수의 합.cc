#include <iostream>
#include <vector>
#define modNum 1000000000
using namespace std;

int main(void) {
  int n, k;
  cin >> n;

  vector<vector<int>> dp(1, vector<int>(n + 1));

  dp[0][0] = 1, k = 1;
  for (int i = 1; k <= n; i++, k *= 2) {
    dp.push_back(vector<int>(n + 1));

    for (int j = 0; j <= n; j++) {
      if (j - k >= 0) {
        dp[i][j] = ((dp[i - 1][j] % modNum) + (dp[i][j - k] % modNum)) % modNum;
      } else {
        dp[i][j] = dp[i - 1][j] % modNum;
      }
    }
  }

  cout << dp.back().back();

  return 0;
}