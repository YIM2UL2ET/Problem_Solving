#include <iostream>
#include <vector>
using namespace std;

int dfs(int cnt, int size, vector <int> &matrix) {
    if (cnt == size) return 1;

    int res = 0;
    for (int i = 0; i < size; i++) {
        bool p = true;
        for (int j = 0; j < cnt; j++) {
            if (matrix[j] == i || cnt-j == abs(matrix[j]-i)) {
                p = false;
                break;
            }
        }
        if (p) matrix[cnt] = i, res += dfs(cnt+1, size, matrix);
    }
    return res;
}

int main(void) {
    int n;
    cin >> n;

    vector <int> matrix(n);
    cout << dfs(0, n, matrix);
    return 0;
}