#include <iostream>
#include <algorithm>
#include <vector>

#define MAXMONEY 5000000

unsigned long long pow (int x, int y);

int main(void)
{
    int cnt;
    std::cin >> cnt;

    for (int i = 0; i < cnt; i++) {
        std::vector <int> vec;
        int buf;
        unsigned long long result = 0;

        std::cin >> buf;
        while (buf != 0) {
            vec.push_back(buf);
            std::cin >> buf;
        }

        std::sort(vec.rbegin(), vec.rend());
        
        for (int j = 0; j < vec.size(); j++) {
            result += 2 * pow(vec[j], j+1);
            if (result > MAXMONEY) break;
        }

        if (result > MAXMONEY) std::cout << "Too expensive" << std::endl;
        else std::cout << result << std::endl;
    }
    
    return 0;
}

unsigned long long pow (int x, int y)
{
    unsigned long long result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}