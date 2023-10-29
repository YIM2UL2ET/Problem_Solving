#include <stdio.h>

int main(void)
{
    char alphabet;
    int i, sum = 0;
    while (1)
    {
        scanf("%c", &alphabet);
        if (alphabet == '#') break;
        else if (alphabet == '\n')
        {
            printf("%d\n", sum);
            sum = 0;
        }
        else if (alphabet == 'a' || alphabet == 'e' || alphabet == 'i' || alphabet == 'o' || alphabet == 'u') sum++;
        else if (alphabet == 'A' || alphabet == 'E' || alphabet == 'I' || alphabet == 'O' || alphabet == 'U') sum++;
    }
    
    return 0;
}