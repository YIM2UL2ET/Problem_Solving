#include <iostream>
#include <algorithm>
#include <vector>

struct node {
    bool isworm = false;
    std::vector <int> link;
};

void worm(std::vector <node> &graph, int n) {
    graph[n].isworm = true;
    for (int com : graph[n].link) {
        if (!graph[com-1].isworm) worm(graph, com-1);
    }
    return;
}

int main(void)
{
    int n, m, a, b, res;
    std::cin >> n >> m;

    std::vector <node> graph(n);
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b;
        graph[a-1].link.push_back(b);
        graph[b-1].link.push_back(a);
    }
    
    worm(graph, 0);
    res = std::count_if(graph.begin(), graph.end(), [](node com) -> bool {return com.isworm;}) - 1;
    std::cout << res;
    return 0;
}