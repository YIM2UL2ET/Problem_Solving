#include <iostream>
#include <cstdlib>
#include <algorithm>

void Solve(void);
int FindDistance(std::string standard, std::string comp);

int main(void)  
{
    int i, testcase;
    std::cin >> testcase;

    for (i = 0; i < testcase; i++) Solve();
    
    return 0;
}

void Solve(void)
{
    int i, j, n;
    std::string word;
    std::cin >> word >> n;

    std::string words[n];
    int distances[n];

    for (i = 0; i < n; i++) {
        std::cin >> words[i];
        distances[i] = FindDistance(word, words[i]);

        int index = i;
        for (j = i; j > 0; j--) {
            if (distances[j-1] > distances[index] || (distances[j-1] == distances[index] && words[j-1] > words[index])) {
                std::swap(distances[j-1], distances[index]);
                std::swap(words[j-1], words[index]);
                index = j-1;
            }
            else break;
        }
    }
    
    for (i = 0; i < n; i++) {
        std::cout << words[i] << " " << distances[i] << std::endl;;
    }
}

int FindDistance(std::string standard, std::string comp)
{
    int i, j, len, result = 0;
    std::string keyboard[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    len = standard.size();

    for (i = 0; i < len; i++) {
        int si, sj, ci, cj;

        for (j = 0; j < 3; j++) {
            auto temp1 = keyboard[j].find(standard[i]);
            if (temp1 != std::string::npos) {
                si = j;
                sj = temp1;
            }
            
            auto temp2 = keyboard[j].find(comp[i]);
            if (temp2 != std::string::npos) {
                ci = j;
                cj = temp2;
            }
        }

        result += abs(si - ci) + abs(sj - cj);
    }

    return result;
}