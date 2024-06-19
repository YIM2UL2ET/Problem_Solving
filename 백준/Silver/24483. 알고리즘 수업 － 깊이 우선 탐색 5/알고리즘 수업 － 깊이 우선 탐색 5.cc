#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct node {
  bool isVst = false;
  vector<int> edge;
};

static long long ans;
static int vstNum;
vector<node> nodes;

void dfs(int n, int depth) {
  nodes[n].isVst = true;
  ans += (long long)depth * (long long)vstNum;
  vstNum++;

  for (int e : nodes[n].edge) {
    if (!nodes[e].isVst) {
      dfs(e, depth + 1);
    }
  }
}

bool comp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first == p2.first) return p1.second < p2.second;
  return p1.first < p2.first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, start;
  cin >> N >> M >> start;

  vector<pair<int, int>> edge(M);
  for (auto &e : edge) {
    cin >> e.first >> e.second;
  }

  sort(edge.begin(), edge.end(), comp);

  nodes.resize(N + 1);
  for (auto e : edge) {
    nodes[e.first].edge.push_back(e.second);
    nodes[e.second].edge.push_back(e.first);
  }

  ans = 0;
  vstNum = 1;
  dfs(start, 0);

  cout << ans;
  return 0;
}