#include <iostream>
using namespace std;

int main(void) {
  int R, C, K;
  cin >> R >> C >> K;

  if (K == 1) {
    cout << 1;
  } else if (R % 2 == 0 || C % 2 == 0) {
    cout << 1;
  } else {
    cout << 0;
  }

  return 0;
}