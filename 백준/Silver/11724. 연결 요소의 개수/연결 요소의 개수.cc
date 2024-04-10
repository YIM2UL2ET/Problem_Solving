#include <iostream>
#include <vector>

struct node {
    std::vector <node*> linked_points; 
    bool isvisit = false;
};

void dfs(node &nd) {
    nd.isvisit = true;
    for (node* &n : nd.linked_points) {
        if (!n->isvisit) dfs(*n);
    }
}

int main(void) {
    int n, m, res = 0;
    std::cin >> n >> m;

    std::vector <node> graph(n);
    for (int i = 0; i < m; i++) {
        int s, e;
        std::cin >> s >> e;
        graph[s-1].linked_points.push_back(&graph[e-1]);
        graph[e-1].linked_points.push_back(&graph[s-1]);
    }
    
    for (auto &nd : graph) {
        if (!nd.isvisit) dfs(nd), res++;
    }
    
    std::cout << res;
    return 0;
}