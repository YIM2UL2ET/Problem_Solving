#include <stdio.h>

int main(void)
{
    char ary[11];
    int age, weight;
    
    while (1)
    {
        scanf("%s %d %d", ary, &age, &weight);
        if (ary[0] == '#' && age == 0 && weight == 0) break;
        else if (age > 17 || weight >= 80) printf("%s Senior\n", ary);
        else printf("%s Junior\n", ary);
    }
    return 0;
}