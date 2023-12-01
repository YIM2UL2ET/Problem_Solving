#include <stdio.h>

int main(void)
{
    char n;
    scanf("%c", &n);
    if (n == 'M') printf("MatKor");
    else if (n == 'W') printf("WiCys");
    else if (n == 'C') printf("CyKor");
    else if (n == 'A') printf("AlKor");
    else printf("$clear");
    return 0;
}