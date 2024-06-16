#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> root;
unordered_map<string, int> treeSize;

string findRoot(string &n) {
  if (n != root[n]) {
    root[n] = findRoot(root[n]);
  }
  return root[n];
}

void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  string A, B;
  for (int i = 0; i < N; i++) {
    cin >> A >> B;

    if (root.find(A) == root.end()) {
      root.insert({A, A});
      treeSize.insert({A, 1});
    }
    if (root.find(B) == root.end()) {
      root.insert({B, B});
      treeSize.insert({B, 1});
    }

    string rootA, rootB;
    rootA = findRoot(A);
    rootB = findRoot(B);

    if (rootA != rootB) {
      root[rootB] = rootA;
      treeSize[rootA] += treeSize[rootB];
    }

    cout << treeSize[rootA] << '\n';
  }

  root.clear();
  treeSize.clear();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve();
  }
  return 0;
}