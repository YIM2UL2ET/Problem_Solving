#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> leftCard;
vector<int> rightCard;
vector<vector<int>> dp;

int func(int l, int r) {
  if (l == N || r == N)
    return 0;
  else if (dp[l][r] == 0) {
    dp[l][r] = max(func(l + 1, r), func(l + 1, r + 1));

    if (leftCard[l] > rightCard[r]) {
      dp[l][r] = max(dp[l][r], func(l, r + 1) + rightCard[r]);
    }
  }
  return dp[l][r];
}

int main(void) {
  cin >> N;

  leftCard.resize(N);
  rightCard.resize(N);
  dp.resize(N, vector<int>(N));

  for (int &card : leftCard) {
    cin >> card;
  }
  for (int &card : rightCard) {
    cin >> card;
  }

  cout << func(0, 0);

  return 0;
}