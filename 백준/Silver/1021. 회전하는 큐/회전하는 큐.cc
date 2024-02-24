#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    int n, m, k, front, result;
    std::vector <int> vec;

    std::cin >> n >> m;
    for (int i = 0; i < n;) vec.push_back(++i);

    result = 0, front = 0;
    for (int i = 0; i < m; i++) {
        std::cin >> k;

        int idx = std::distance(vec.begin(), std::find(vec.begin(), vec.end(), k));
        int distance = abs(front - idx);

        if (distance < vec.size() - distance) result += distance;
        else result += vec.size() - distance;

        front = idx;
        vec.erase(vec.begin()+front);
    }
    
    std::cout << result;
    return 0;   
}