#include <stdio.h>

int main(void)
{
    int i, j, sizeA, sizeB, differance = 0, min= 0;  
    char aryA[51], aryB[51];
    scanf("%s %s", aryA, aryB);
    for (i = 0; aryA[i] != '\0'; i++)
    sizeA = i+1;
    for (i = 0; aryB[i] != '\0'; i++)
    sizeB = i+1;
    for (i = 0; i <= sizeB - sizeA; i++)
    {
        for (j = 0; j < sizeA; j++)
        {
            if (aryA[j] != aryB[i + j]) differance++;
        }
        if(i == 0) min = differance;
        else min = min < differance ? min : differance;
        differance = 0;
    }
    printf("%d", min);
    return 0;
}