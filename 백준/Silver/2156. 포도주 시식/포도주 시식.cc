#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector <int> juices(n);
    for (int &juice : juices) {
        cin >> juice;
    }

    vector <int> dp(n+3);
    dp[0] = juices[0];
    dp[1] = juices[0] + juices[1];
    dp[2] = max(dp[1], max(dp[0] + juices[2], juices[1] + juices[2]));
    for (int i = 3; i < n; i++) {
        dp[i] = max(dp[i-1], max(dp[i-2] + juices[i], dp[i-3] + juices[i-1] + juices[i]));
    }
    
    cout << dp[n-1];
    return 0;
}