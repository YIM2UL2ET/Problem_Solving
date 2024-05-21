#include <iostream>
#define C 900528
using namespace std;

int main(void) {
  string chars, target;
  cin >> chars >> target;

  int ans = 0, K = 1; // K = chars.size()^n (n = 0, 1, 2, ... pwSize-1)
  int pwSize = target.size();
  for (int i = 1; i <= pwSize; i++) {
    ans += (((chars.find(target[pwSize - i]) + 1) % C) * (K % C)) % C;
    ans %= C;

    K = ((K % C) * (chars.size() % C)) % C;
  }

  cout << ans;

  return 0;
}