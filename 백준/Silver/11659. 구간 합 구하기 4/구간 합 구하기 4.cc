#include <iostream>
#include <vector>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m, k, i, j;
    std::cin >> n >> m;

    std::vector <int> vec(n+1, 0);
    for (int i = 1; i < n+1; i++) {
        std::cin >> k;
        vec[i] = vec[i-1] + k;
    }
    
    for (int cnt = 0; cnt < m; cnt++) {
        std::cin >> i >> j;
        std::cout << vec[j] - vec[i-1] << '\n';
    }
    return 0;
}