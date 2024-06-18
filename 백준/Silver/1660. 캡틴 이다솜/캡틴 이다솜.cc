#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> dp;
vector<int> cannonBall;

void cannonBallSet() {
  int i = 1, value = 0, temp = 0;

  while (value <= N) {
    temp += i;
    value += temp;
    i++;
    cannonBall.push_back(value);
  }
  cannonBall.pop_back();
}

int solve(int n) {
  if (n == 0) return 0;

  if (dp[n] == 0) {
    dp[n] = INT32_MAX;

    for (int ball : cannonBall) {
      if (ball <= n) {
        dp[n] = min(dp[n], solve(n - ball) + 1);
      } else {
        break;
      }
    }
  }

  return dp[n];
}

int main() {
  cin >> N;

  dp.resize(N + 1);
  cannonBallSet();

  for (int ball : cannonBall) {
    dp[ball] = 1;
  }

  cout << solve(N);
  return 0;
}