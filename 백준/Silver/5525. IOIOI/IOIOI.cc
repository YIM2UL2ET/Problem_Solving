#include <iostream>
#include <queue>
using namespace std;

int main(void) {
  char ch;
  int N, M;
  queue<char> Pn, target;

  cin >> N >> M;

  for (int i = 0; i < N * 2 + 1; i++) {
    cin >> ch;
    target.push(ch);

    if (i % 2 == 0) {
      Pn.push('I');
    } else {
      Pn.push('O');
    }
  }

  int ans = 0;
  if (Pn == target) {
    ans++;
  }
  for (int i = 2 * N + 1; i < M; i++) {
    cin >> ch;
    target.pop();
    target.push(ch);

    if (target == Pn) {
        ans++;
    }
  }

  cout << ans;
  return 0;
}