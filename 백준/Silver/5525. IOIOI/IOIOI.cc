#include <iostream>
using namespace std;

int main(void) {
  int N, M;
  string S;

  cin >> N >> M >> S;

  int ans = 0;
  int oddI = 0, oddO = 0;
  int evenI = 0, evenO = 0;
  
  for (int i = 0; i < M; i++) {
    if (i % 2 == 0) {
      if (S[i] == 'I') {
        evenI++;
        evenO = 0;
        if(evenI >= N + 1 && oddO >= N) ans++;
      } else {
        evenO++;
        evenI = 0;
      }
    } else {
      if (S[i] == 'I') {
        oddI++;
        oddO = 0;
        if(oddI >= N + 1 && evenO >= N) ans++;
      } else {
        oddO++;
        oddI = 0;
      }
    }
  }

  cout << ans;
  return 0;
}