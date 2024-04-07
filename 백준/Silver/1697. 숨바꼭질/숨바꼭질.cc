#include <iostream>
#include <vector>
#include <queue>

int bfs (int n, int m) {
    if (n > m) return n - m;

    std::vector <bool> dp(m+2, false);
    std::queue <int> que;
    int res = m - n, time = 0;

    que.push(n);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            if (que.front() >= m) res = res < que.front()-m + time ? res : que.front()-m + time;
            else {
                dp[que.front()] = true;
                if (que.front() > 0 && !dp[que.front()-1]) que.push(que.front()-1);
                if (que.front()+1 > m || !dp[que.front()+1]) que.push(que.front()+1);
                if (que.front()*2 > m || !dp[que.front()*2]) que.push(que.front()*2);
            }
            que.pop();
        }
        time++;
    }
    return res;
}

int main(void) {
    int n, m;
    std::cin >> n >> m;

    std::cout << bfs(n, m);
    return 0;
}