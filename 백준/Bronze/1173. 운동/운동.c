#include <stdio.h>

int main(void)
{
    int exsTime, min, max, increase, decrease, pulse, totalTime;
    scanf("%d %d %d %d %d", &exsTime, &min, &max, &increase, &decrease);
    totalTime = 0;
    pulse = min;

    if (max - min < increase)
    {
        printf("-1");
        return 0;
    }

    while (exsTime != 0)
    {
        if (pulse + increase <= max)
        {
            pulse += increase;
            exsTime--;
        }
        else if (pulse - decrease > min)
        {
            pulse -= decrease;
        }
        else if (pulse - decrease <= min)
        {
            pulse = min;
        }
        totalTime++;
    }

    printf("%d", totalTime);

    return 0;
}