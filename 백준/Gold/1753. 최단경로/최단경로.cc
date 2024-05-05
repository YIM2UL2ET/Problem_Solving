#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
using namespace std;

struct info{int node, distance;};
vector <vector <info>> ary;
vector <int> dp;

void dijkstra (int start) {
    dp[start] = 0;
    priority_queue<pair <int, int>> heap;
    heap.push({0, start});

    while (!heap.empty()) {
        int distance = -1 * heap.top().first;
        int idx = heap.top().second;
        heap.pop();

        if (distance <= dp[idx]) {
            for (int i = 0; i < ary[idx].size(); i++) {
                int nextLink = ary[idx][i].node;
                int nextDistance = ary[idx][i].distance + distance;

                if (nextDistance < dp[nextLink]) {
                    dp[nextLink] = nextDistance;
                    heap.push({-1 * nextDistance, nextLink});
                }
            }
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int v, e, n;
    cin >> v >> e >> n;

    ary.resize(v);
    dp.resize(v, INF);
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        ary[u-1].push_back({v-1, w});
    }

    dijkstra(n-1);

    for (int distance : dp) {
        if (distance == INF) cout << "INF\n";
        else cout << distance << '\n';
    }
    
    return 0;
}