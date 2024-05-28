#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int N;
  cin >> N;

  vector<int> maxBefore(3);
  vector<int> minBefore(3);
  vector<int> maxNow(3);
  vector<int> minNow(3);

  for (int i = 0; i < 3; i++) {
    cin >> minNow[i];
    maxNow[i] = minNow[i];
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      minBefore[j] = minNow[j];
      maxBefore[j] = maxNow[j];

      cin >> maxNow[j];
      minNow[j] = maxNow[j];
    }

    maxNow[0] += max(maxBefore[0], maxBefore[1]);
    maxNow[1] += max(maxBefore[0], max(maxBefore[1], maxBefore[2]));
    maxNow[2] += max(maxBefore[1], maxBefore[2]);

    minNow[0] += min(minBefore[0], minBefore[1]);
    minNow[1] += min(minBefore[0], min(minBefore[1], minBefore[2]));
    minNow[2] += min(minBefore[1], minBefore[2]);
  }

  cout << max(maxNow[0], max(maxNow[1], maxNow[2])) << ' '
       << min(minNow[0], min(minNow[1], minNow[2])) << endl;

  return 0;
}