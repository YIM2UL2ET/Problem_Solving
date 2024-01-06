#include <stdio.h>
#include <string.h>

int CompareWord(char *target_word, char *word, int target_word_len, int word_len);
void ChangeWord(char *target_ary, char *word, int len);

int main(void)
{
    int i, j, k, w, h, index;
    char temp[21] = {'\0'}, result[21] = {'\0'};
    scanf("%d %d", &h, &w);
    char puzzle[h][w];

    getchar();

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++) 
        {
            puzzle[i][j] = getchar();
        }
        getchar();
    }
    
    for (i = 0; i < h; i++)
    {
        index = 0;
        for (j = 0; j < w; j++) 
        {
            if (puzzle[i][j] == '#')
            {
                temp[index] = '\0';
                index = 0;
                if (strlen(temp) > 1 && CompareWord(result, temp, strlen(result), strlen(temp)) == 1) ChangeWord(result, temp, strlen(temp));
            }
            else temp[index++] = puzzle[i][j];
        }
        temp[index] = '\0';
        if (strlen(temp) > 1 && CompareWord(result, temp, strlen(result), strlen(temp)) == 1) ChangeWord(result, temp, strlen(temp));
    }

    for (i = 0; i < w; i++)
    {
        index = 0;
        for (j = 0; j < h; j++) 
        {
            if (puzzle[j][i] == '#')
            {
                temp[index] = '\0';
                index = 0;
                if (strlen(temp) > 1 && CompareWord(result, temp, strlen(result), strlen(temp)) == 1) ChangeWord(result, temp, strlen(temp));
            }
            else temp[index++] = puzzle[j][i];
        }
        temp[index] = '\0';
        if (strlen(temp) > 1 && CompareWord(result, temp, strlen(result), strlen(temp)) == 1) ChangeWord(result, temp, strlen(temp));
    }
    
    printf("%s", result);
    return 0;
}

int CompareWord(char *target_word, char *word, int target_word_len, int word_len)
{
    int i, len;
    len = word_len < target_word_len ? word_len : target_word_len; 
    
    for (i = 0; i < len; i++)
    {
        if (word[i] < target_word[i]) return 1;
        else if (word[i] > target_word[i]) return -1;
    }
    
    if (target_word_len == 0) return 1;
    else if(word_len < target_word_len) return 1;
    else if(word_len > target_word_len) return -1;
    else return 0;
}

void ChangeWord(char *target_ary, char *word, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        target_ary[i] = word[i];
    }
    target_ary[i] = '\0';
}