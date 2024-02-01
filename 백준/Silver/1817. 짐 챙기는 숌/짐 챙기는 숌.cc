#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    int n, m, result;
    std::cin >> n >> m;
    std::vector <int> weights(n);
    for (int i = 0; i < n; i++) std::cin >> weights[i];

    result = 0;
    while (weights.size() > 0) {
        result++;
        int temp = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (temp + weights[i] <= m) {
                temp += weights[i];
                weights.erase(weights.begin()+i);
                i--;
            }
            else break;
        }
    }
    
    std::cout << result;
    return 0;
}