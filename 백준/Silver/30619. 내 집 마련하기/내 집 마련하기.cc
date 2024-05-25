#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int N, M, Ai;
  cin >> N;

  vector<int> indexs(N);
  for (int i = 0; i < N; i++) {
    cin >> Ai;
    indexs[Ai - 1] = i;
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    int L, R;
    vector<int> A(N);
    auto temp = indexs;

    cin >> L >> R;
    sort(temp.begin() + L - 1, temp.begin() + R);

    for (int i = 0; i < N; i++) {
      A[temp[i]] = i + 1;
    }

    for (int a : A) {
      cout << a << ' ';
    }
    cout << '\n';
  }

  return 0;
}
