#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  long long N, K;
  double temp;
  cin >> N >> K;

  vector<long long> scores(N);
  vector<long long> sum(N + 1);
  
  for (long long &score : scores) {
    cin >> temp;
    score = temp * 1000;
  }

  sort(scores.begin(), scores.end());

  for (int i = 1; i <= N; i++) {
    sum[i] = sum[i - 1] + scores[i - 1];
  }

  long long middle = sum[N - K] - sum[K];
  long long ans1 = middle / (N - K * 2);
  long long ans2 = (middle + scores[K] * K + scores[N - K - 1] * K) / N;

  if (ans1 % 10 >= 5) {
    ans1 = ans1 / 10 + 1;
  } else {
    ans1 = ans1 / 10;
  }

  if (ans2 % 10 >= 5) {
    ans2 = ans2 / 10 + 1;
  } else {
    ans2 = ans2 / 10;
  }

  printf("%.2lf\n%.2lf", ans1 / 100.0, ans2 / 100.0);
  return 0;
}