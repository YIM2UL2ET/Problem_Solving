#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> edge;
vector<bool> isTeam;
vector<bool> isVisit;

int dfs(unordered_set<int> &localVst, int n) {
  if (isVisit[n]) return 0;

  int result = 0;
  isVisit[n] = true;
  localVst.insert(n);

  if (localVst.find(edge[n]) == localVst.end()) {
    result = dfs(localVst, edge[n]);
  } else {
    result = edge[n];
  }

  if (result > 0) {
    isTeam[n] = true;
    if (result != n) {
      return result;
    } else {
      return 0;
    }
  }
  return 0;
}

void solve(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, ans;
  cin >> n;

  edge.resize(n + 1);
  isTeam.resize(n + 1, false);
  isVisit.resize(n + 1, false);

  for (int i = 1; i <= n; i++) {
    cin >> edge[i];
  }

  for (int i = 1; i <= n; i++) {
    unordered_set<int> localVst;
    dfs(localVst, i);
  }

  ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!isTeam[i]) ans++;
  }

  cout << ans << '\n';

  edge.clear();
  isTeam.clear();
  isVisit.clear();
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }

  return 0;
}