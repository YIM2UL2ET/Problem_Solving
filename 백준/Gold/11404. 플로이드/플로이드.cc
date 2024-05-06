#include <iostream>
#include <vector>
#define INF 100000000
using namespace std;

void floyd (vector <vector <int>> &dp, int size) {
    for (int m = 0; m < size; m++) {
        for (int s = 0; s < size; s++) {
            for (int e = 0; e < size; e++) {
                if (dp[s][e] > dp[s][m] + dp[m][e]) {
                    dp[s][e] = dp[s][m] + dp[m][e];
                }
            }
        }
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> dp(n, vector <int> (n, INF));

    for (int i = 0; i < n; i++) dp[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (dp[u-1][v-1] > w) dp[u-1][v-1] = w;
    }

    floyd(dp, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == INF) cout << 0 << ' ';
            else cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}