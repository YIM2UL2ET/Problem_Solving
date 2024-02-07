#include <iostream>
#include <array>

int main(void)
{
    int n, m;
    std::cin >> n >> m;

    std::string str[n];
    for (int i = 0; i < n; i++) {
        std::cin >> str[i];
    }

    int r_value = 0;
    char r_str[m+1] = {'\0'};

    for (int i = 0; i < m; i++) {
        int max, index;
        std::array <int, 26> alpha = {0};
        
        for (int j = 0; j < n; j++) {
            alpha[str[j][i] - 65]++;
        }

        max = 0;
        for (int j = 0; j < 26; j++) {
            if (max < alpha[j]) {
                max = alpha[j];
                index = j;
            }
        }

        r_str[i] = index + 65;
        r_value += n - max;
    }
    
    std::cout << r_str << std::endl << r_value;
    return 0;
}