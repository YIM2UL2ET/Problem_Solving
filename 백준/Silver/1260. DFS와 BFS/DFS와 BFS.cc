#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

struct node {
    std::vector <int> idx;
    bool vst = false;
};

void dfs(std::vector <node> &graph, int n) {
    std::cout << n << ' ';
    graph[n-1].vst = true;

    for (int idx : graph[n-1].idx) {
        if (!graph[idx-1].vst) dfs(graph, idx);
    }
    return;
}

void bfs(std::vector <node> &graph, int n) {
    std::cout << n << ' ';
    graph[n-1].vst = true;

    std::queue <int> que;
    for (int idx : graph[n-1].idx) {
        graph[idx-1].vst = true, que.push(idx);
    }
    
    while (!que.empty()) {
        std::cout << que.front() << ' ';
        for (int idx : graph[que.front()-1].idx) {
            if (!graph[idx-1].vst) {
                graph[idx-1].vst = true, que.push(idx);
            }
        }
        que.pop();
    }
    return;
}

int main(void)
{
    int n, m, v;
    std::cin >> n >> m >> v;

    std::vector <node> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        graph[a-1].idx.push_back(b);
        graph[b-1].idx.push_back(a);
    }

    for (int i = 0; i < n; i++) std::sort(graph[i].idx.begin(), graph[i].idx.end());
    
    dfs(graph, v);
    std::cout << '\n';
    for (int i = 0; i < n; i++) graph[i].vst = false;
    bfs(graph, v);

    return 0;
}