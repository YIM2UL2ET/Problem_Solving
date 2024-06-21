#include <iostream>
using namespace std;

int func(int n) {
  if (n <= 2) return n;
  return func(n - 1) + func(n - 2);
}

int main() {
  string target;
  cin >> target >> target;

  int ans = 1;
  int idx = 0;
  int temp = 0;

  while (idx < target.size()) {
    if (target.substr(idx, 4) == "long") {
      temp++;
      idx += 4;
    } else {
      ans *= max(1, func(temp));
      temp = 0;
      idx++;
    }
  }
  ans *= max(1, func(temp));

  cout << ans;
  return 0;
}