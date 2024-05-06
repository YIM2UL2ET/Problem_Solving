#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
using namespace std;

vector <int> dijkstra (vector <vector <pair <int, int>>> &info, int size, int start) {
    vector <int> dp(size, INF);
    priority_queue <pair <int, int>> heap;

    for (auto in : info[start]) {
        dp[in.second] = in.first;
    }
    
    dp[start] = 0;
    heap.push({0, start});

    while (!heap.empty()) {
        int distance = -heap.top().first;
        int node = heap.top().second;
        heap.pop();

        if (distance <= dp[node]) {
            for (int i = 0; i < info[node].size(); i++) {
                int nextNode = info[node][i].second;
                int nextDistance = info[node][i].first + distance;

                if (nextDistance <= dp[nextNode]) {
                    dp[nextNode] = nextDistance;
                    heap.push({-nextDistance, nextNode});
                } 
            }
            
        }
    }
    
    return dp;
}

int main(void) {
    int n, m, x;
    cin >> n >> m >> x;

    vector <vector <pair <int, int>>> info(n);
    vector <vector <pair <int, int>>> reverseInfo(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        info[u-1].push_back({w, v-1});
        reverseInfo[v-1].push_back({w, u-1});
    }
    
    vector <int> result1 = dijkstra(info, n, x-1);
    vector <int> result2 = dijkstra(reverseInfo, n, x-1);
    priority_queue <int> result;

    for (int i = 0; i < n; i++) {
        result.push(result1[i] + result2[i]);
    }
    
    cout << result.top();
    return 0;
}