#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int N;
  cin >> N;

  vector<int> nums(N);
  vector<vector<long long>> dp(N - 1, vector<long long>(21));

  for (int &num : nums) {
    cin >> num;
  }

  dp[0][nums[0]] = 1;
  for (int i = 1; i <= N - 2; i++) {
    for (int num = 0; num <= 20; num++) {
      if (num + nums[i] <= 20) {
        dp[i][num + nums[i]] += dp[i - 1][num];
      }
      if (num - nums[i] >= 0) {
        dp[i][num - nums[i]] += dp[i - 1][num];
      }
    }
  }

  cout << dp[N - 2][nums.back()];
  return 0;
}