#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<int> A(n);
  for (int &a : A) {
    cin >> a;
  }

  sort(A.begin(), A.end());

  int m;
  cin >> m;

  vector<pair<int, int>> nums(m);
  for (int i = 0; i < m; i++) {
    cin >> nums[i].first;
    nums[i].second = i;
  }

  sort(nums.begin(), nums.end(),
       [](pair<int, int> n1, pair<int, int> n2) -> bool {
         return n1.first < n2.first;
       });

  auto Ai = A.begin();
  auto it = nums.begin();
  vector<bool> ans(m);
  while (Ai != A.end() && it != nums.end()) {
    if (*Ai < it->first) {
      Ai++;
    } else if (*Ai > it->first) {
      it++;
    } else {
      ans[it->second] = true;
      it++;
    }
  }

  for (bool r : ans) {
    cout << r << '\n';
  }

  return 0;
}