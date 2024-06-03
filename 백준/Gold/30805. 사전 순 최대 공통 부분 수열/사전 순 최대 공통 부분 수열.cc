#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool comp(pair<int, int> v1, pair<int, int> v2) {
  if (v1.first == v2.first) return v1.second < v2.second;
  return v1.first > v2.first;
}

int main(void) {
  int N, M, temp;
  vector<int> ans;

  cin >> N;
  vector<pair<int, int>> A;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    A.push_back({temp, i});
  }

  cin >> M;
  vector<int> B;
  for (int i = 0; i < M; i++) {
    cin >> temp;
    B.push_back(temp);
  }

  sort(A.begin(), A.end(), comp);

  int lastAIdx = -1, lastBIdx = -1;
  for (int i = 0; i < N; i++) {
    if (A[i].second < lastAIdx) continue;

    for (int j = lastBIdx + 1; j < M; j++) {
      if (A[i].first == B[j]) {
        ans.push_back(B[j]);
        lastAIdx = A[i].second;
        lastBIdx = j;
        break;
      }
    }
  }
  
  cout << ans.size() << '\n';
  for (int element : ans) {
    cout << element << ' ';
  }

  return 0;
}