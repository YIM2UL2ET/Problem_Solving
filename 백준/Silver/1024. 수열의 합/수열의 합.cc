#include <iostream>
using namespace std;

int main(void) {
  int N, L;
  cin >> N >> L;

  for (int l = L; l <= 100; l++) {
    int sum = l * (l - 1) / 2;
    if (N - sum < 0) break;
    else if ((N - sum) % l == 0) {
      for (int i = 0; i < l; i++) {
        cout << (N - sum) / l + i << ' ';
      }
      return 0;
    }
  }
  cout << -1;
  return 0;
}