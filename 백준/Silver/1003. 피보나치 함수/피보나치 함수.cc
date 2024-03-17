#include <iostream>
#include <vector>

int main(void)
{
    std::vector <std::pair <int, int>> dp;
    dp.push_back({1,0});
    dp.push_back({0,1});

    int n, k;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> k;
        if (dp.size() <= k) {
            for (int i = dp.size(); i <= k; i++) {
                dp.push_back({dp[i-1].first+dp[i-2].first, dp[i-1].second+dp[i-2].second});
            }
        }
        std::cout << dp[k].first << ' ' << dp[k].second << '\n';
    }
    
    return 0;
}