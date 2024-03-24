#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    int n, buf, res;
    std::cin >> n;

    std::vector <int> dp(n);
    
    std::cin >> dp[0];
    res = dp[0];
    for (int i = 1; i < n; i++) {
        std::cin >> buf;
        if (dp[i-1] + buf < buf) dp[i] = buf;
        else dp[i] = dp[i-1] + buf;
        if (res < dp[i]) res = dp[i];
    }

    std::cout << res;
    return 0;
}
