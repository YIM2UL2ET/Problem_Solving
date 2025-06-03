#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
vector <unordered_map<int, int>> tree;
vector <long long> cnt_memo; // 자식노드의 개수
vector <long long> ans_memo; // 정답 메모

void dfs1(int cur_node, int par_node, int dist) {
    ans_memo[cur_node] = dist;
    cnt_memo[cur_node] = 0;
    
    for (auto &nxt_node : tree[cur_node]) {
        if (nxt_node.first == par_node) continue;
        
        dfs1(nxt_node.first, cur_node, dist + nxt_node.second);
        ans_memo[cur_node] += ans_memo[nxt_node.first];
        cnt_memo[cur_node] += cnt_memo[nxt_node.first] + 1;
    }
}

void dfs2(int cur_node, int par_node, int dist) {
    ans_memo[cur_node] = ans_memo[par_node] + (N - 2*cnt_memo[cur_node] - 2) * dist;
    
    for (auto &nxt_node : tree[cur_node]) {
        if (nxt_node.first == par_node) continue;
        dfs2(nxt_node.first, cur_node, nxt_node.second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    tree.resize(N + 1);
    ans_memo.resize(N + 1);
    cnt_memo.resize(N + 1);
    
    int u, v, w;
    for (int i = 1; i < N; i++) {
        cin >> u >> v >> w;
        tree[u].insert({v, w});
        tree[v].insert({u, w});
    }
    
    dfs1(1, 0, 0);
    ans_memo[0] = ans_memo[1];
    cnt_memo[0] = cnt_memo[1];
    dfs2(1, 0, 0);
    
    for (int i = 1; i <= N; i++) {
        cout << ans_memo[i] << '\n';
    }
    
    return 0;
}