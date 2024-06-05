#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<int> dp(n + 1, INT32_MAX);
  vector<int> set{0, INT32_MAX, 1, INT32_MAX, 2, 1};

  for (int i = 0; i <= min(n, 5); i++) {
    dp[i] = set[i];
  }

  for (int i = 6; i <= n; i++) {
    dp[i] = min(dp[i - 2], dp[i - 5]) + 1;
  }

  if (dp[n] == INT32_MAX)
    cout << -1;
  else
    cout << dp[n];

  return 0;
}