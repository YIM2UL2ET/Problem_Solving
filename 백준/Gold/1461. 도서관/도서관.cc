#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    int n, m, temp, result;
    std::vector <int> negative;
    std::vector <int> positive;
    std::vector <int> distance;
    
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        if (temp > 0) positive.push_back(temp);
        else negative.push_back(abs(temp));
    }
    
    std::sort(positive.begin(), positive.end());
    std::sort(negative.begin(), negative.end());

    for (int i = positive.size()-1; (i+1)/m > 0; i-=m) distance.push_back(positive[i]);
    for (int i = negative.size()-1; (i+1)/m > 0; i-=m) distance.push_back(negative[i]);
    if (positive.size() % m != 0) distance.push_back(positive[positive.size()%m -1]);
    if (negative.size() % m != 0) distance.push_back(negative[negative.size()%m -1]);
    
    std::sort(distance.rbegin(), distance.rend());
    
    result = 0;
    for (int i = 1; i < distance.size(); i++) result += distance[i] * 2;
    result += distance[0];
    
    std::cout << result;
    return 0;
}