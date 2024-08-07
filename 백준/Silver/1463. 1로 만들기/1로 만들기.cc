#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
    int n;
    std::cin >> n;
    
    std::vector <int> dp(1000001);
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1]+1;
        if (i % 3 == 0) dp[i] = std::min(dp[i], dp[i/3]+1);
        if (i % 2 == 0) dp[i] = std::min(dp[i], dp[i/2]+1);
    }
    
    std::cout << dp[n];
    return 0;
}