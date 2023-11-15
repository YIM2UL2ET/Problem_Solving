#include <stdio.h>

int main(void)
{
    int i, roomNum, sixAndNine = 0, max = 0;
    int needNum[9] = {0};
    scanf("%d", &roomNum);
    while (1)
    {
        if (roomNum % 10 != 6 && roomNum % 10 != 9) needNum[roomNum % 10]++;
        else sixAndNine++;

        if (roomNum < 10) break;
        roomNum /= 10;
    }
    if (sixAndNine % 2 != 0) sixAndNine++;
    sixAndNine /= 2;
    needNum[6] += sixAndNine;
    for (i = 0; i < 9; i++)
    {
        max = max > needNum[i] ? max : needNum[i];
    }
    printf("%d", max);
    return 0;
}