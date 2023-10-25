#include <stdio.h>
#include <stdlib.h>

int compare (void *first, void *second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else 
        return 0;
}

int main (void)
{
    int i, j, qNum, max = -1, sum = 0;
    int scores[8], questionNums[5];

    for (i = 0; i < 8; i++)
    {
        scanf("%d", &scores[i]);
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (max < scores[j])
            {
                max = scores[j];
                qNum = j+1;
            }
        }
        scores[qNum-1] = -1;
        sum += max;
        questionNums[i] = qNum;
        max = -1;
        qNum = 0;
    }
    
    qsort(questionNums, 5, 4, compare);
    
    printf("%d\n", sum);
    for (i = 0; i < 5; i++) printf("%d ", questionNums[i]);
    
    return 0;
}