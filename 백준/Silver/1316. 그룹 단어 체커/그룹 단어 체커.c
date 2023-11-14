#include <stdio.h>
#include <string.h>

int check_group_word(char *word, int len);

int main(void)
{
    int i, n, len, result = 0;
    char word[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", word);
        len = strlen(word);
        if (check_group_word(word, len)) result++;
    }
    printf("%d\n", result);
    return 0;
}

int check_group_word(char *word, int len)
{
    int i;
    char tmp = '!';
    char alphabet[28] = "qwertyuiopasdfghjklzxcvbnm!";
    for (i = 0; i < len; i++)
    {
        if (tmp != word[i])
        {
            if (!strchr(alphabet, tmp)) return 0;
            *strchr(alphabet, tmp) = '?';
        }
        tmp = word[i];
    }
    if (!strchr(alphabet, tmp)) return 0;
    return 1;
}