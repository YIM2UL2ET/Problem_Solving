#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
  long long n, ans;
  cin >> n;

  vector<long long> pt(n);
  for (long long &p : pt) {
    cin >> p;
  }

  sort(pt.begin(), pt.end());

  if (n % 2 == 1) {
    ans = pt.back();
    pt.pop_back();
  } else {
    ans = 0;
  }

  long long left = 0;
  long long right = pt.size() - 1;
  while (left < right) {
    ans = max(ans, pt[left] + pt[right]);
    left++;
    right--;
  }
  
  cout << ans;
  return 0;
}