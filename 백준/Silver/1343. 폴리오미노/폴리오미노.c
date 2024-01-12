#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;
    char *x;
    char ary[51];
    scanf("%s", ary);

    while(1) {
        x = strstr(ary, "XXXX");
        if (x != '\0') {
            for (i = 0; i < 4; i++) x[i] = 'A';
        }
        else {
            x = strstr(ary, "XX");
            if (x != '\0') {
                for (i = 0; i < 2; i++) x[i] = 'B';
            }
            else {
                x = strstr(ary, "X");
                if (x != '\0') printf("-1");
                else printf("%s", ary);
                return 0;
            }
        }
    }
    
}