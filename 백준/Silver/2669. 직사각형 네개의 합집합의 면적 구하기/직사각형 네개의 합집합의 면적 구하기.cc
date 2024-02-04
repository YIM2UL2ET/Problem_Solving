#include <iostream>

int main(void)
{
    char table[100][100] = {'0'};
    for (int c = 0; c < 4; c++) {
        int lx, ly, rx, ry;
        std::cin >> lx >> ly >> rx >> ry;

        for (int i = lx-1; i < rx-1; i++) {
            for (int j = ly-1; j < ry-1; j++) {
                table[i][j] = '1';
            }   
        }
    }

    int result = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (table[i][j] == '1') result++;
        }   
    }
    
    std::cout << result;
    return 0;
}