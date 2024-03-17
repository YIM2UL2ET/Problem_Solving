#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    int n, k;
    long long res = 0;
    std::cin >> n >> k;
    
    std::vector <int> vec(n);
    for (int i = 0; i < n; i++) std::cin >> vec[i];
    std::sort(vec.begin(), vec.end());

    res += vec.back();
    for (int i = 0; i < (k-1)/2; i++) {
        res += vec[n-2-i] - vec[i];
    }
    
    std::cout << res;
    return 0;
}