#include <stdio.h>

int main(void)
{
    char str[1001];
    int num;

    scanf("%s", str);
    scanf("%d", &num);

    printf("%c", str[num - 1]);

    return 0;
}