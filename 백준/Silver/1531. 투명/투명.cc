#include <iostream>

int main(void)
{
    int matrix[100][100] = {0};
    int n, m, result = 0;

    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1-1; i < y2; i++) {
            for (int j = x1-1; j < x2; j++) matrix[i][j]++;
        }
    }
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (matrix[i][j] > m) result++;
        }
    }
    
    std::cout << result;
    return 0;
}