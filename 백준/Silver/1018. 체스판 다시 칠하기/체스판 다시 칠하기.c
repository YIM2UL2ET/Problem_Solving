#include <stdio.h>

int paintSquareNum(int row, int col, char (*chessBoard)[50]);

int main(void)
{
    int length, height, i, j, result, tmp;
    scanf("%d %d", &height, &length);
    result = length * height;

    char chessBoard[height][50];
    for (i = 0; i < height; i++)
    {
        scanf("%s", chessBoard[i]);
    }
    
    for (i = 0; i <= height-8; i++)
    {
        for (j = 0; j <= length-8; j++)
        {
            tmp = paintSquareNum(i, j, chessBoard);
            if (result > tmp) result = tmp;
        }
    }
    
    printf("%d", result);

    return 0;
}

int paintSquareNum(int row, int col, char (*chessBoard)[50])
{
    int i, j, result = 0;

    for (i = row; i < row+8; i++)
    {
        for (j = col; j < col+8; j++)
        {
            if((i+j) % 2 == 0 && chessBoard[i][j] == 'B') result++;
            else if ((i+j) % 2 == 1 && chessBoard[i][j] == 'W') result++;
        }
    }
    
    if (64 - result < result) result = 64 - result;
    return result;
}