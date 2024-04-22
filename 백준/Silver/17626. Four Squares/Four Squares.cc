#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector <int> dp(50000);

int solve(int target) {
    if (!target) return 0;
    else if (!dp[target-1]) {
        int result = INT32_MAX;
        int max_divisor = int(sqrt(target));

        for (int divisor = max_divisor; divisor > 0; divisor--) {
            if (target / (divisor * divisor) > result) break;
            else {
                int quotient = target / (divisor * divisor);
                int remain = target % (divisor * divisor);
                int temp = solve(remain) + quotient;
                result = min(result, temp);
            }
        }
        
        dp[target-1] = result;
    }

    return dp[target-1];
}

int main(void) {
    int target;
    cin >> target;
    cout << solve(target);
    return 0;
}