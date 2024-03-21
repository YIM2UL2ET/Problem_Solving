#include <iostream>

int main(void)
{
    int n, m, res = 0;
    bool g = false;
    std::cin >> n >> m;
    
    std::string str[n];
    for (int i = 0; i < n; i++) std::cin >> str[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (str[i][j] == '-' && !g) g = true;
            else if (str[i][j] == '|' && g) g = false, res++;
        }
        if (g) g = false, res++;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (str[j][i] == '|' && !g) g = true;
            else if (str[j][i] == '-' && g) g = false, res++;
        }
        if (g) g = false, res++;
    }

    std::cout << res;
    return 0;
}