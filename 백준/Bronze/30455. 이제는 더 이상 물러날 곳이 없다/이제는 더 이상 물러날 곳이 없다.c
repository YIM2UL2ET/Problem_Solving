#include <stdio.h>

int main(void)
{
    int n, goose, duck;
    scanf("%d", &n);
    duck = 1; goose = n;
    while (1)
    {
        duck++;
        if (duck == goose)
        {
            printf("Duck");
            return 0;
        }
        goose--;
        if (duck == goose)
        {
            printf("Goose");
            return 0;
        }
    }
}