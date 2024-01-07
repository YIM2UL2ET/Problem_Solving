#include <stdio.h>

int main(void)
{
    char paper[100][100] = {'O'};    
    int i, j, k, n, x, y, result = 0;
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        for (j = x; j < x+10; j++)
        {
            for (k = 90-y; k < 100-y; k++)
            {
                paper[j][k] = 'X';
            }
        }
    }

    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
        {
            if(paper[i][j] == 'X') result++;
        }
    }
    
    printf("%d", result);
    return 0;
}