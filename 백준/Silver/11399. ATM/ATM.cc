#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
    int n, res = 0;
    std::cin >> n;
    std::vector <int> vec(n);
    for (int i = 0; i < n; i++) std::cin >> vec[i];

    std::sort(vec.begin(), vec.end());
    res += vec.front();
    for (int i = 1; i < n; i++) {
        vec[i] += vec[i-1], res += vec[i];
    }
    std::cout << res;
    return 0;
}