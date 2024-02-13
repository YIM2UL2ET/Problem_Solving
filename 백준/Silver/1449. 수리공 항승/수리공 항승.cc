#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    int result, n, l, cover_size;
    std::cin >> n >> l;

    std::vector <int> location(n);
    for (int i = 0; i < n; i++) {
        std::cin >> location[i];
    }
    
    std::sort(location.begin(), location.end());

    cover_size = 0, result = 0;
    for (int i = 0; i < n; i++) {
        if (cover_size < location[i]) {
            cover_size = location[i]+l-1;
            result++;
        }
    }
    
    std::cout << result;
    return 0;
}