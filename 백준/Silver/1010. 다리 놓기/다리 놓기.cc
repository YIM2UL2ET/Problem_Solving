#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector <vector <int>> dp (30, vector <int> (30));

    for (int i = 0; i < 30; i++) {
        dp[0][i] = i+1;
    }

    for (int i = 1; i < 30; i++) {
        int sum = 0;
        for (int j = i; j < 30; j++) {
            sum += dp[i-1][j-1];
            dp[i][j] = sum;
        }
    }

    int t, n, m;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        cout << dp[n-1][m-1] << '\n';
    }

    return 0;
}