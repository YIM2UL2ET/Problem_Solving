#include <iostream>
#include <algorithm>
#include <unordered_map>

int main(void)
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n, m;
    std::string ad, pw;

    std::cin >> n >> m;
    std::unordered_map <std::string, std::string> hash;
    for (int i = 0; i < n; i++) {
        std::cin >> ad >> pw;
        hash.insert({ad, pw});
    }
    for (int i = 0; i < m; i++) {
        std::cin >> ad;
        auto it = hash.find(ad);
        std::cout << it->second << '\n';
    }
    return 0;
}