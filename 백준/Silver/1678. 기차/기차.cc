#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    int t, m, n, result, m_up;
    std::cin >> t >> m >> n;

    std::vector <std::pair<int, std::string>> information;

    m_up = 0;
    for (int i = 0; i < t; i++) {
        int temp;
        std::string str;

        std::cin >> str >> temp;
        while (temp != -1) {
            std::pair <int, std::string> p;
            p.first = temp;
            p.second = str;
            information.push_back(p);
            if (temp >= m) m_up++;

            std::cin >> temp;
        }
    }

    std::sort(information.begin(), information.end());
    
    if (n <= m_up) result = information.size()- m_up + n - 1;
    else result = (n - m_up - 1) % information.size();

    std::cout << information[result].second;
    return 0;
}