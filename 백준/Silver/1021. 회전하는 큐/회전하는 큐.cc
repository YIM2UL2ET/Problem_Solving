#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    int n, m, k, idx, front, result;
    std::vector <int> vec;

    std::cin >> n >> m;
    for (int i = 0; i < n;) {
        vec.push_back(++i);
    }

    result = 0, front = 0;
    for (int i = 0; i < m; i++) {
        std::cin >> k;

        std::vector <int> :: iterator iter;
        iter = std::find(vec.begin(), vec.end(), k);
        idx = std::distance(vec.begin(), iter);

        if (abs(front - idx) < vec.size() - abs(front - idx)) result += abs(front - idx);
        else result += vec.size() - abs(front - idx);

        front = idx;
        vec.erase(vec.begin()+front);
    }
    
    std::cout << result;
    return 0;   
}