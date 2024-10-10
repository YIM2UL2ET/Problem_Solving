#include <iostream>
#include <vector>
#include <queue>

#define INF 1e8

using namespace std;

int N, M;
vector <vector <pair <int, int>>> graph;
vector <pair <int, int>> check_edge;

int dijkstra(int u, int v) {
    vector <int> dist(N + 1, INF);
    priority_queue <pair <int, int>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int cur_cost = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (cur_cost > dist[cur_node]) continue;

        for (auto &e : graph[cur_node]) {
            int nxt_cost = e.second + dist[cur_node];
            int nxt_node = e.first;
            
            if ((nxt_node == u && cur_node == v) || (nxt_node == v && cur_node == u)) continue;
            
            if (nxt_cost < dist[nxt_node]) {
                dist[nxt_node] = nxt_cost;
                pq.push({-nxt_cost, nxt_node});
                if (u == 0 && v == 0) check_edge.push_back({cur_node, nxt_node});
            }
        }
    }

    return dist[N];
}

int main() {
    // fastIO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // init && input
    cin >> N >> M;
    graph.resize(N + 1);

    int u, v, w;
    for (int i = 1; i <= M; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    // solve
    int ans = 0;
    int orizinal_time = dijkstra(0, 0);
    if (orizinal_time != INF) {
        for (auto &e : check_edge) {
            int temp = dijkstra(e.first, e.second);
            if (temp != INF) {
                ans = max(ans, temp - orizinal_time);
            } else {
                ans = -1;
                break;
            }
        }
    } else {
        ans = -1;
    }
    
    // output
    cout << ans;
    return 0;
}