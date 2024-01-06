#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j, w, h, index;
    char temp[21] = {'\0'}, result[21] = "zzzzzzzzzzzzzzzzzzzz";
    scanf("%d %d", &h, &w);
    char puzzle[h][w];

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++) 
        {
            scanf(" %c", &puzzle[i][j]);
        }
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
                if (strlen(temp) > 1 && strcmp(result, temp) > 0) strcpy(result, temp);
            }
            else temp[index++] = puzzle[i][j];
        }
        temp[index] = '\0';
        if (strlen(temp) > 1 && strcmp(result, temp) > 0) strcpy(result, temp);
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
                if (strlen(temp) > 1 && strcmp(result, temp) > 0) strcpy(result, temp);
            }
            else temp[index++] = puzzle[j][i];
        }
        temp[index] = '\0';
        if (strlen(temp) > 1 && strcmp(result, temp) > 0) strcpy(result, temp);
    }
    
    printf("%s", result);
    return 0;
}