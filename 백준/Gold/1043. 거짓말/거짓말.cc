#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    bool visit = false;
    vector <int> link;
};

vector <int> linking(int n, vector <node> &graph) {
    int k;
    vector <int> list;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int h : list) {
            if (find(graph[h-1].link.begin(), graph[h-1].link.end(), k) == graph[h-1].link.end()) {
                graph[h-1].link.push_back(k);
                graph[k-1].link.push_back(h);
            }
        }
        list.push_back(k);
    }
    return list;
}

void dfs(vector <node> &graph, int n) {
    graph[n-1].visit = true;
    for (int nd : graph[n-1].link) {
        if (!graph[nd-1].visit) dfs(graph, nd);
    }
}

int main(void) {
    int n, m, k, res = 0;
    cin >> n >> m;

    vector <node> graph(n);

    cin >> k;
    vector <int> known(k);
    vector <vector <int>> party;
    for (int &p : known) cin >> p;

    for (int i = 0; i < m; i++) {
        cin >> k;
        party.push_back(linking(k, graph));
    }

    for (int &p : known) dfs(graph, p);

    for (auto &p : party) {
        bool o = true;
        for (int i : p) {
            if (graph[i-1].visit) {
                o = false;
                break;
            }
        }
        if (o) res++;
    }
    
    cout << res;
    return 0;
}