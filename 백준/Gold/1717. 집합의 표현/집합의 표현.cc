#include <iostream>
#include <vector>
using namespace std;

static vector<int> root;

int findRoot(int x) {
  if (x != root[x]) {
    root[x] = findRoot(root[x]);
  }
  return root[x];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, command, a, b;
  cin >> N >> M;

  root.resize(N + 1);
  for (int i = 1; i <= N; i++) {
    root[i] = i;
  }

  for (int i = 0; i < M; i++) {
    cin >> command >> a >> b;

    int rootA, rootB;
    rootA = findRoot(a);
    rootB = findRoot(b);

    if (command == 0) {
      root[rootB] = rootA;
    } else if (rootA == rootB) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}