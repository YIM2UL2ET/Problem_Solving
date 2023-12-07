#include <stdio.h>

int main(void)
{
    int i, a, n, result = 1;
    scanf("%d", &n);
    for (i = 2; i < n; i++)
    {
        for (a = 1; a < n; a++)
        {
            if ((i * (2 * a + (i - 1))) / 2 == n) 
            {
                result++;
                break;
            }
            else if ((i * (2 * a + (i - 1))) / 2 > n) break;
        }
        if (a == 1) break;
    }
    
    printf("%d", result);
    return 0;
}