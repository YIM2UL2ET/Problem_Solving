#include <stdio.h>

int main(void)
{
    int n, m, k, i, j, p, sum = 0;

    // 행렬 A의 요소 입력
    scanf("%d %d", &n, &m);
    int matrixA[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &matrixA[i][j]);
        }
    }

    // 행렬 B의 요소 입력
    scanf("%d %d", &m, &k);
    int matrixB[m][k];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < k; j++)
        {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // 행렬 곱셈
    int matrixM[n][k];
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < n; j++)
        {
            // 매트릭스m의 요소인 sum 구하기
            for (p = 0; p < m; p++)
            {
                sum += matrixA[j][p] * matrixB[p][i];
            }
            matrixM[j][i] = sum;
            sum = 0;
        }
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            printf("%d ", matrixM[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}