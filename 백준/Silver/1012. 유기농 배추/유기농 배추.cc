#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

void bfs(std::vector <std::pair <int, int>> &list) {
    std::pair <int, int> offset[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    std::queue <std::pair <int, int>> que;

    que.push({list.back().first, list.back().second});
    list.pop_back();
    while (!que.empty()) {
        for (auto set : offset) {
            std::pair <int, int> tmp = {que.front().first + set.first, que.front().second + set.second};
            auto it = std::find(list.begin(), list.end(), tmp);
            if (it != list.end()) que.push(*it), list.erase(it);
        }
        que.pop();
    }
    return;
}

void solve(void) {
    int n, m, k, res = 0;

    std::cin >> n >> m >> k;
    std::vector <std::pair <int, int>> list;

    for (int i = 0; i < k; i++) {
        int y, x;
        std::cin >> y >> x;
        list.push_back({y,x});
    }

    while (!list.empty()) res++, bfs(list);
    
    std::cout << res << '\n';
    return;
}

int main(void) {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}