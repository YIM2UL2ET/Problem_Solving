#include <iostream>
#include <vector>
using namespace std;

int maxValue, endNode;

struct node {
    bool visit = false;
    vector <pair <int, int>> link;
};

void dfs(vector <node> &tree, int n, int value) {
    tree[n].visit = true;
    if (value > maxValue) maxValue = value, endNode = n;
    for (auto nd : tree[n].link) {
        if (!tree[nd.first].visit) dfs(tree, nd.first, value + nd.second);
    }
}

int main(void) {
    int n, idx, nodeIdx, nodeValue;
    cin >> n;

    vector <node> tree(n);
    for (int i = 0; i < n; i++) {
        cin >> idx;
        cin >> nodeIdx;
        while (nodeIdx != -1) {
            cin >> nodeValue;
            tree[idx-1].link.push_back({nodeIdx-1,nodeValue});
            cin >> nodeIdx;
        }
    }

    auto copyTree = tree;
    dfs(copyTree, 0, 0);
    dfs(tree, endNode, 0);
    cout << maxValue;
    return 0;
}