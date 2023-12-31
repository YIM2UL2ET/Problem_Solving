#include <stdio.h>

int main(void)
{
    char num[5];
    int i, result;
    while(1)
    {
        result = 0;
        scanf("%s", num);
        if (num[0] == '0') break;
        for (i = 0; num[i] != '\0'; i++)
        {
            result++;
            if (num[i] == '1') result += 2;
            else if (num[i] == '0') result += 4;
            else result += 3;
        }
        result++;
        printf("%d\n", result);
            
    }
    return 0;
}