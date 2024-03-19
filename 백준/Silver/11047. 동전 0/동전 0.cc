#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    int n, k, res = 0;
    std::cin >> n >> k;

    std::vector <int> coins(n);
    for (int i = 0; i < n; i++) std::cin >> coins[i];

    std::sort(coins.rbegin(), coins.rend());
    for (int i = 0; k > 0; i++) {
        res += k / coins[i];
        k %= coins[i];
    }
    
    std::cout << res;
    return 0;
}