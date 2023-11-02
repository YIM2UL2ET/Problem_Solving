#include <stdio.h>

int main(void)
{
    char std[1000], doc[1000];
    int i;
    scanf("%s", std);
    scanf("%s", doc);
    for (i = 0; i < 1000; i++)
    {
        if(doc[i] == 'h')
        {
            printf("go");
            return 0;
        }
        else if(std[i] == 'h') 
        {
            printf("no");
            return 0;
        }
    }
}