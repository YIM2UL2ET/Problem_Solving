#include <stdio.h>

int find_num_of_ask(int studentNum, int *answerAry);

int main(void)
{
    int i, n, numOfAsk, result, max = 0;
    scanf("%d", &n);
    int answerAry[n];
    
    for (i = 0; i < n; i++)
    {
        scanf("%d", &answerAry[i]);
    }
    
    for (i = 0; i < n; i++)
    {
        numOfAsk  = find_num_of_ask(i+1, answerAry);
        if (max < numOfAsk)
        {
            max = numOfAsk;
            result = i+1;
        }
    }
    printf("%d", result);
    return 0;
}

int find_num_of_ask(int studentNum, int *answerAry)
{
    int result = 0;
    int isAnswer[1000] = {0};
    isAnswer[studentNum-1] = 1;
    while (1)
    {
        if (isAnswer[answerAry[studentNum-1]-1] == 0)
        {
            isAnswer[answerAry[studentNum-1]-1] = 1;
            studentNum = answerAry[studentNum-1];
            result++;
        }
        else break;
    }
    return result;
}