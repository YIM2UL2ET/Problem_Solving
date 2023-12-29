#include <stdio.h>

int main(void)
{
    int h, m, s, add;
    scanf("%d %d %d %d", &h, &m, &s, &add);
    s += add % 60;
    m += add / 60;


    while (s >= 60)
    {
        s -= 60;
        m++;
    }
    while (m >= 60)
    {
        m -= 60;
        h++;
    }
    while (h >= 24) h -= 24;
    printf("%d %d %d", h, m, s);
    return 0;
}