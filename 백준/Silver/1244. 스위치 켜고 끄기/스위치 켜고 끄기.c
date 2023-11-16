#include <stdio.h>

void change_man_switch(int *switchs, int len, int num);
void change_woman_switch(int *switchs, int len, int num);
void print_switchs(int *switchs, int len);

int main(void)
{
    int i, n, len, gen, num;
    int j;
    scanf("%d", &len);

    int switchs[len];
    for (i = 0; i < len; i++) {scanf("%d", &switchs[i]);}

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &gen, &num);
        if (gen == 1) change_man_switch(switchs, len, num);
        else change_woman_switch(switchs, len, num);
    }
    
    print_switchs(switchs, len);

    return 0;
}

void change_man_switch(int *switchs, int len, int num)
{
    int i;
    for (i = 1; num * i -1 < len; i++)
    {
        if(switchs[num * i -1]) switchs[num * i -1] = 0;
        else switchs[num * i -1] = 1;
    }
    return;    
}

void change_woman_switch(int *switchs, int len, int num)
{
    int i;
    for (i = 0; num + i -1 < len && num - i -1 >= 0; i++)
    {
        if (switchs[num + i -1] == switchs[num - i -1] && switchs[num + i -1] == 1)
        {
            switchs[num + i -1] = 0;
            switchs[num - i -1] = 0;
        }
        else if (switchs[num + i -1] == switchs[num - i -1] && switchs[num + i -1] == 0)
        {
            switchs[num + i -1] = 1;
            switchs[num - i -1] = 1;
        }
        else break;
    }
    return;
}

void print_switchs(int *switchs, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d ", switchs[i]);
        if ((i+1) % 20 == 0) printf("\n");
    }
    return;
}