#include <iostream>
#include <unordered_map>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m;
    char ch;
    std::string key;
    std::cin >> n >> m;

    std::unordered_map <std::string, int> string_map;
    std::unordered_map <int, std::string> digit_map;
    for (int i = 0; i < n; i++) {
        std::cin >> key;
        string_map.insert({key, i+1});
        digit_map.insert({i+1, key});
    }
    
    for (int i = 0; i < m; i++) {
        std::cin >> ch;
        std::cin.unget();
        if (ch >= 'A' && ch <= 'Z') {
            std::cin >> key;
            std::cout << string_map[key] << '\n';
        }
        else {
            std::cin >> n;
            std::cout << digit_map[n] << '\n';
        }
    }
    return 0;
}