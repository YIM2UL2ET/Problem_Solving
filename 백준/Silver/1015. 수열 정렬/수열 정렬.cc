#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int n, v;
  cin >> n;

  vector<pair<int, int>> A(n);
  for (int i = 0; i < n; i++) {
    cin >> v;
    A[i] = {v, i};
  }

  sort(A.begin(), A.end(), [](pair<int, int> p1, pair<int, int> p2) -> bool {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
  });

  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[A[i].second] = i;
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }

  return 0;
}