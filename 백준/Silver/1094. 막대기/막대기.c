#include <stdio.h>

int main(void)
{
    int x, answer, stick;

    answer = 0;
    stick = 64;

    scanf("%d", &x);
    
    while (x != 0)
    {
        while (x < stick)
        {
            stick = stick / 2;
        }

        x -= stick;
        stick = stick / 2;
        answer++;
    }
    
    printf("%d", answer);
    
    return 0;
}