#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Edge {
  int vtx, cap, rvs;
  Edge(int v, int c, int r) : vtx(v), cap(c), rvs(r) {}
};

struct Dinic {
  int n;
  vector<int> dist, cnt;
  vector<bool> vst;
  vector<vector<Edge>> adj;

  Dinic(int n) : n(n), dist(n), vst(n), adj(n), cnt(n) {}

  void add_edge(int u, int v, int c) {
    adj[u].emplace_back(v, c, adj[v].size());
    adj[v].emplace_back(u, 0, adj[v].size() - 1);
  }

  bool bfs(int s, int t) {
    queue<int> Q;
    Q.push(s);

    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;

    while (!Q.empty()) {
      int sz = Q.size();
      while (sz--) {
        int cur = Q.front();
        Q.pop();

        for (auto &[nxt, cap, rvs] : adj[cur]) {
          if (cap > 0 && dist[nxt] == INF) {
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
          }
        }
      }
    }
    return dist[t] < INF;
  }

  int get_flow(int cur, int flow, int &sink) {
    vst[cur] = true;
    if (cur == sink) return flow;
    while (cnt[cur] < adj[cur].size()) {
      auto &[nxt, cap, rvs] = adj[cur][cnt[cur]];
      if (dist[cur] + 1 == dist[nxt] && cap > 0 && !vst[nxt]) {
        int res = get_flow(nxt, min(flow, cap), sink);
        if (res) {
          cap -= res;
          adj[nxt][rvs].cap += res;
          return res;
        }
      }
      cnt[cur]++;
    }
    return 0;
  }

  int max_flow(int s, int t) {
    int mf = 0;
    while (bfs(s, t)) {
      int res = 0;
      fill(vst.begin(), vst.end(), false);
      fill(cnt.begin(), cnt.end(), 0);
      while (res = get_flow(s, INF, t)) {
        mf += res;
        fill(vst.begin(), vst.end(), false);
      }
    }
    return mf;
  }

  void print_ans(int s) {
    fill(vst.begin(), vst.end(), false);
    vst[s] = true;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty()) {
      int cur = Q.front();
      Q.pop();

      bool res = false;
      for (auto &[nxt, cap, rvs] : adj[cur]) {
        if (cap > 0 && !vst[nxt]) {
          vst[nxt] = true;
          res = true;
          Q.push(nxt);
        }
      }
    }

    for (int i = 0; i < n / 2; i++) {
      if (vst[i] && !vst[i + n / 2]) cout << i + 1 << ' ';
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, S, T;
  cin >> N >> M >> S >> T;

  int u, v, w;
  Dinic dinic(N * 2);

  S = S - 1, T = T - 1 + N;
  for (int i = 0; i < N; i++) {
    cin >> w;
    dinic.add_edge(i, i + N, w);
  }

  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    dinic.add_edge(u + N - 1, v - 1, INF);
    dinic.add_edge(v + N - 1, u - 1, INF);
  }

  int mf = dinic.max_flow(S, T);
  dinic.print_ans(S);
  return 0;
}