#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    int n, m;
    std::cin >> n >> m;

    std::vector <int> v;
    for (int i = 0; i < n;) v.push_back(++i);

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        std::reverse(v.begin()+a-1, v.begin()+b);
    }
    
    for (int i = 0; i < n; i++) std::cout << v[i] << " ";
    return 0;
}