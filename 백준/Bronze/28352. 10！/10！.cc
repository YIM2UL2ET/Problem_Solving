#include <iostream>
using namespace std;

int main(void) {
  int n;
  cin >> n;

  int ans = 6;
  for (int i = 11; i <= n; i++) {
    ans *= i;
  }

  cout << ans;
  return 0;
}