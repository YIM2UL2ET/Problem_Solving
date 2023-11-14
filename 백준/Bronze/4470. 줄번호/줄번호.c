#include <stdio.h>

int main(void)
{
    int i, n;
    char string[101];
    scanf("%d", &n); 
    getchar();
    for (i = 1; i <= n; i++)
    {
        gets(string);
        printf("%d. %s\n", i, string);
    }
    return 0;
}