#include <iostream>
#include <vector>
using namespace std;

vector<int> idxSeq;
string target;

void solve(int left, int right) {
  if (left > right) return;

  int minIndex = left;
  for (int i = left; i <= right; i++) {
    if (target[i] < target[minIndex]) {
      minIndex = i;
    }
  }

  idxSeq.push_back(minIndex);
  solve(minIndex + 1, right);
  solve(left, minIndex - 1);
}

int main(void) {
  cin >> target;
  int size = target.size();

  solve(0, size - 1);

  vector<bool> isChPrint(size, false);
  for (int idx : idxSeq) {
    isChPrint[idx] = true;

    for (int i = 0; i < size; i++) {
      if (isChPrint[i]) {
        cout << target[i];
      }
    }
    cout << '\n';
  }

  return 0;
}