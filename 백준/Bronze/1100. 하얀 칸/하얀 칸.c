#include <stdio.h>

int main(void)
{
    char chessboard[8][9];
    int i, j, answer = 0;

    for (i = 0; i < 8; i++)
    {
        scanf("%s", chessboard[i]);
    }

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0 && chessboard[i][j] == 'F') answer++;
            }
            else
            {
                if (j % 2 == 1 && chessboard[i][j] == 'F') answer++;
            }
        }
    }

    printf("%d", answer);

    return 0;
}

// 코드 내가 짯지만 개허졉이내..