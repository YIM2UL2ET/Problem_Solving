// 나중에 코드 수정 예정

#include <stdio.h>

int main(void)
{   
    char x;
    int i = 0, intX = 0, y = 0, answer = 0;

    
    while (1)
    {
        scanf("%c", &x);
        if (x == 10) break;
        y += ((int)x - 48);
        i++;
    }
    if (i > 1) answer++;

    if (y < 10)
    {
        printf("%d\n", answer);
        if (y % 3 == 0) printf("YES");
        else printf("NO");
        return 0;
    }

    intX = y;
    y = 0;

    while (1)
    {
        while (intX != 0)
        {
            y += intX % 10;
            intX /= 10;
        }
        answer++;

        if (y < 10) break;
        
        intX = y;
        y = 0;
    }
    
    printf("%d\n", answer);
    if (y % 3 == 0) printf("YES");
    else printf("NO"); 

    return 0;
}