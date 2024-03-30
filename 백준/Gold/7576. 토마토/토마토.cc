#include <iostream>
#include <vector>
#include <queue>

struct idx {int y, x;};

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, n, h, res = 0, non = 0;
    std::vector <idx> offset = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    std::queue <idx> que[2];
    bool curQueue = false;

    std::cin >> n >> m;
    int box[m][n];

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            std::cin >> box[y][x];
            if (box[y][x] == 1) que[curQueue].push({y, x});
            else if (box[y][x] == 0) non++;
        }
    }

    while (!que[curQueue].empty() && non > 0) {
        while (!que[curQueue].empty()) {
            int y = que[curQueue].front().y, x = que[curQueue].front().x;
            for (idx set : offset) {
                int yy = y + set.y, xx = x + set.x;
                if (yy >= 0 && yy < m && xx >= 0 && xx < n && box[yy][xx] == 0) {
                    box[yy][xx] = 1, non--;
                    que[!curQueue].push({yy, xx});
                }
            }
            que[curQueue].pop();
        }
        curQueue = !curQueue;
        res++;
    }

    if (non > 0) std::cout << -1;
    else std::cout << res;
    
    return 0;
}