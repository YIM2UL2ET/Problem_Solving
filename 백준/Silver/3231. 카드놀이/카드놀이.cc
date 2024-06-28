#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k, ans;
  cin >> n;

  vector<int> idx(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> k;
    idx[k] = i;
  }

  ans = 0;
  for (int i = 2; i <= n; i++) {
    if (idx[i] < idx[i - 1]) ans++;
  }

  cout << ans;
  return 0;
}