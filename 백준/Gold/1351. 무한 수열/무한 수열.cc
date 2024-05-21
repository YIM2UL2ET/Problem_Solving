#include <iostream>
#include <unordered_map>
using namespace std;

int P, Q;
unordered_map <long long, long long> dp;

long long A(long long N) {
  if(dp.find(N) == dp.end()) {
    dp[N] = A(N / Q) + A(N / P);
  }
  return dp[N];
}

int main(void) {
  long long N;
  cin >> N >> P >> Q;

  dp[0] = 1;
  cout << A(N);

  return 0;
}