#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int N, M, R;
vector <bool> visited;
priority_queue <pair <int, int>> pq;    // first = -cost, second = node
vector <vector <pair <int, int>>> relation; // first = 노드, second = 감소값
vector <int> memo;  // memo[i] = i번째 알고리즘의 최소값

int main() {
    // fastIO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // init && input
    cin >> N >> M;

    visited.resize(N + 1, false);
    relation.resize(N + 1);
    memo.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> memo[i];
        pq.push({-memo[i], i});
    }

    cin >> R;
    int u, v, w;
    for (int i = 1; i <= R; i++) {
        cin >> u >> v >> w;
        relation[u].push_back({v, w});
    }

    // sovle
    int ans = 0;
    for (int i = 1; i <= M; i++) {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node]) {
            i--; continue;
        }
        
        visited[node] = true;
        ans = max(ans, cost);
        for (auto &r : relation[node]) {
            memo[r.first] -= r.second;
            pq.push({-memo[r.first], r.first});
        }
    }

    // output
    cout << ans;
    return 0;
}