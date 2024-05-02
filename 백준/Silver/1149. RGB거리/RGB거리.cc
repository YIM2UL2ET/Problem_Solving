#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n;
    vector <int> dp(3);
    vector <int> now(3);

    cin >> n;

    for (int i = 0; i < n; i++) {
        vector <int> temp(3);
        cin >> now[0] >> now[1] >> now[2];

        temp[0] = min(dp[1], dp[2]) + now[0];
        temp[1] = min(dp[0], dp[2]) + now[1];
        temp[2] = min(dp[0], dp[1]) + now[2];

        dp[0] = temp[0];
        dp[1] = temp[1];
        dp[2] = temp[2];
    }

    cout << min(min(dp[0], dp[1]), dp[2]);
    return 0;
}