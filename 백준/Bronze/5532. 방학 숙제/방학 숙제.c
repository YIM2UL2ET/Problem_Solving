#include <stdio.h>

int main(void)
{
    int l, a, b, c, d;
    int max, kor, math = 0;
    scanf("%d", &l);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    kor = a / c;
    if (a % c != 0) kor++;
    math = b / d;
    if (b % d != 0) math++;

    max = (kor > math) ? kor : math;
    l -= max;
    
    printf("%d", l);

    return 0;
}