#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct node {
  unordered_set<int> edge;
};

int orderOfVstIdx;
vector<bool> isVisit;
vector<int> orderOfVst;
vector<node> tree;

void dfs(int nodeIdx) {
  isVisit[nodeIdx] = true;
  auto &edge = tree[nodeIdx].edge;

  while (1) {
    if (edge.find(orderOfVst[orderOfVstIdx]) != edge.end()) {
      dfs(orderOfVst[orderOfVstIdx++]);
    } else {
      break;
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, parent, child;
  cin >> N;

  tree.resize(N + 1);
  for (int i = 1; i < N; i++) {
    cin >> parent >> child;
    tree[parent].edge.insert(child);
    tree[child].edge.insert(parent);
  }

  orderOfVst.resize(N);
  for (int &element : orderOfVst) {
    cin >> element;
  }

  orderOfVstIdx = 1;
  isVisit.resize(N + 1, false);

  dfs(1);

  int ans = 1;
  for (int i = 1; i <= N; i++) {
    if (!isVisit[i]) ans = 0;
  }
  cout << ans;

  return 0;
}