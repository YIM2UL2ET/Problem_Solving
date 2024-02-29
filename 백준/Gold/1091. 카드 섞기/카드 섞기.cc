#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    int n, result = 0;
    std::cin >> n;

    int s[n], p[n];
    for (int i = 0; i < n; i++) std::cin >> p[i];
    for (int i = 0; i < n; i++) std::cin >> s[i];
    
    std::vector <std::vector <int>> goals(3);
    std::vector <int> cards(n);
    std::vector <int> shuffle(n);
    std::vector <int> start;

    for (int i = 0; i < n; i++) {
        goals[p[i]].push_back(i);
        cards[i] = i;
    } 
    start = cards;

    while (true) {
        int i;
        for (i = 0; i < n; i++) {
            if (goals[i%3].size() == std::find(goals[i%3].begin(), goals[i%3].end(), cards[i]) - goals[i%3].begin()) {
                for (int j = 0; j < n; j++) shuffle[s[j]] = cards[j];
                cards = shuffle;
                result++;
                break;
            }
        }
        if (i == n) {std::cout << result; return 0;}
        else if (start == cards) {std::cout << -1; return 0;}
    }
}