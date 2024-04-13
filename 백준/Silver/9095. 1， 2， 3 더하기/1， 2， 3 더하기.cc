#include <iostream>
#include <vector>

std::vector <int> dp = {1,2,4,0,0,0,0,0,0,0};

int func(int n) {
    if (dp[n-1] == 0) dp[n-1] = func(n-1) + func(n-2) + func(n-3);
    return dp[n-1];
}

int main(void) {
    int cnt, n;

    std::cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        std::cin >> n;
        std::cout << func(n) << '\n';
    }
    return 0;
}