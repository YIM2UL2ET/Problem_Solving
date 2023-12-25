#include <stdio.h>
#include <stdlib.h>

int compare(const void *first, const void *secend);
void PrintPassword(char* chars, char* pw, int pw_index, int chars_index, int num_of_chars, int pw_len);
int CheckCondition(char *pw, int len);

int main(void)
{
    int num_of_char, pw_len, i;
    scanf("%d %d", &pw_len, &num_of_char);
    getchar();

    char chars[num_of_char], pw[pw_len+1];
    pw[pw_len] = '\0';

    for (i = 0; i < num_of_char; i++)
    {
        scanf("%c", &chars[i]);
        getchar();
    }

    qsort(chars, num_of_char, sizeof(char), compare);

    PrintPassword(chars, pw, 0, 0, num_of_char, pw_len);
    
    return 0;
}

int compare(const void *first, const void *secend)
{
    if(*(char*)first > *(char*)secend) return 1;
    else if (*(char*)first > *(char*)secend) return -1;
    else return 0;
}

void PrintPassword(char* chars, char* pw, int pw_index, int chars_index, int num_of_chars, int pw_len)
{
    int i;
    if (pw_index+1 == pw_len)
    {
        for (i = chars_index; i < num_of_chars; i++)
        {
            pw[pw_index] = chars[i];
            if (CheckCondition(pw, pw_len) == 1) printf("%s\n", pw);
        }
    }
    else
    {
        for (i = chars_index; i < num_of_chars; i++)
        {
            pw[pw_index] = chars[i];
            PrintPassword(chars, pw, pw_index+1, i+1, num_of_chars, pw_len);
        }
    }
}

int CheckCondition(char *pw, int len)
{
    int i, consonant = 0, vowel = 0;
    for (i = 0; i < len; i++)
    {
        if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u')
        {
            vowel++;
        }
        else consonant++;
    }
    
    if(consonant < 2 || vowel < 1) return 0;
    return 1;
}