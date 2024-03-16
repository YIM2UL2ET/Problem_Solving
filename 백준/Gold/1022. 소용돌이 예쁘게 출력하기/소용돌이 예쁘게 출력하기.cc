#include <iostream>
int space(int n) {
    int res = 0;
    while (n > 0) n /= 10, res++;
    return res;
}

int main(void)
{
    int r1, c1, r2, c2;
    int r = 0, c = 0, level = 1, n = 1;
    std::string cmd = "right";

    std::cin >> r1 >> c1 >> r2 >> c2;
    int matrix[r2-r1+1][c2-c1+1] = {0};

    while (abs(r) <= 5000 && abs(c) <= 5000) {
        if (cmd == "up") {
            for (int i = r; i > r-level; i--, n++) {
                if (r1 <= i && i <= r2 && c1 <= c && c <= c2)matrix[i-r1][c-c1] = n;
            }
            cmd = "left", r -= level++;
        }
        else if (cmd == "left") {
            for (int i = c; i > c-level; i--, n++) {
                if (r1 <= r && r <= r2 && c1 <= i && i <= c2)matrix[r-r1][i-c1] = n;
            }
            cmd = "down", c -= level;
        }
        else if (cmd == "down") {
            for (int i = r; i < r+level; i++, n++) {
                if (r1 <= i && i <= r2 && c1 <= c && c <= c2)matrix[i-r1][c-c1] = n;
            }
            cmd = "right", r += level++;
        }
        else {
            for (int i = c; i < c+level; i++, n++) {
                if (r1 <= r && r <= r2 && c1 <= i && i <= c2)matrix[r-r1][i-c1] = n;
            }
            cmd = "up", c += level;
        }
    }

    int sp = 0;
    if (space(matrix[0][0]) > sp) sp = space(matrix[0][0]);
    if (space(matrix[0][c2-c1]) > sp) sp = space(matrix[0][c2-c1]);
    if (space(matrix[r2-r1][0]) > sp) sp = space(matrix[r2-r1][0]);
    if (space(matrix[r2-r1][c2-c1]) > sp) sp = space(matrix[r2-r1][c2-c1]);

    for (int i = 0; i <= r2-r1; i++) {
        for (int j = 0; j <= c2-c1; j++) {
            std::cout.width(sp);
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}