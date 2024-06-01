#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> day;
vector<int> price;
vector<int> dp;

int fun(int i) {
    if (i >= N) {
        return 0;
    } else if (dp[i] == -1) {
      if (i + 1 <= N && i + day[i] <= N) {
        dp[i] = max(fun(i + 1), fun(i + day[i]) + price[i]);
      } else if (i + 1 > N && i + day[i] <= N) {
        dp[i] = fun(i + day[i]) + price[i];
      } else if (i + 1 <= N && i + day[i] > N) {
        dp[i] = fun(i + 1);
      } else dp[i] = 0;
    }
    return dp[i];
}

int main(void) {
  cin >> N;

  day.resize(N);
  price.resize(N);
  dp.resize(N, -1);

  for (int i = 0; i < N; i++) {
    cin >> day[i] >> price[i];
  }

  cout << fun(0);
  return 0;
}