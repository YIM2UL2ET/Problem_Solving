#include <iostream>
#include <queue>
using namespace std;

int main(void) {
  int N, K, temp;
  cin >> N >> K;

  queue<int> firGrade;
  queue<int> secGrade;
  for (int i = 0; i < N; i++) {
    cin >> temp;  // grade

    if (temp == 1) {
      firGrade.push(i);
    } else {
      secGrade.push(i);
    }
  }

  int ans = 0;
  int idx = K - 1;
  while (!firGrade.empty() && !secGrade.empty()) {
    ans++;

    temp = 0;  // increase in idx
    if (firGrade.front() <= idx) {
      firGrade.pop();
      temp++;
    }
    if (secGrade.front() <= idx) {
      secGrade.pop();
      temp++;
    }

    idx += temp;
  }

  ans += max(firGrade.size(), secGrade.size());
  cout << ans;

  return 0;
}