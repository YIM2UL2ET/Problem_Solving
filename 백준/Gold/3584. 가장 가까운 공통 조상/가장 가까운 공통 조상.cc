#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> parent;

int dfs(unordered_set<int> &visitNode, int n) {
  if (n == 0) return 0;

  if (visitNode.find(n) == visitNode.end()) {
    visitNode.insert(n);
    return dfs(visitNode, parent[n]);
  } else {
    return n;
  }
}

void solve() {
  int N;
  cin >> N;

  parent.resize(N + 1);

  int A, B;
  for (int i = 1; i < N; i++) {
    cin >> A >> B;
    parent[B] = A;
  }
  cin >> A >> B;

  unordered_set<int> visitNode;
  dfs(visitNode, A);
  int ans = dfs(visitNode, B);

  cout << ans << '\n';
  parent.clear();
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve();
  }

  return 0;
}