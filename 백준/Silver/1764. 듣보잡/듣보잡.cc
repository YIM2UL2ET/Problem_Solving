#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int n, m;
    std::cin >> n >> m;

    std::vector <std::string> no_hear(n);
    std::vector <std::string> no_see(m);
    std::vector <std::string> res;
    for (int i = 0; i < n; i++) std::cin >> no_hear[i];
    for (int i = 0; i < m; i++) std::cin >> no_see[i];

    std::sort(no_hear.begin(), no_hear.end());
    std::sort(no_see.begin(), no_see.end());
    int h_idx = 0, s_idx = 0;
    while (h_idx < n && s_idx < m) {
        if (no_hear[h_idx] > no_see[s_idx]) s_idx++;
        else if (no_hear[h_idx] < no_see[s_idx]) h_idx++;
        else res.push_back(no_hear[h_idx]), s_idx++, h_idx++;
    }
    
    std::cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << '\n';
    }
    return 0;
}