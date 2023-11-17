#include <stdio.h>

int check_thousand_year(int criYaer, int criMonth, int criDay, int comYear, int comMonth, int comDay);

int main(void)
{
    int toYear, toMonth, toDay, endYear, endMonth, endDay, sumDay = 0;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    scanf("%d %d %d", &toYear, &toMonth, &toDay);
    scanf("%d %d %d", &endYear, &endMonth, &endDay);

    if (check_thousand_year(toYear, toMonth, toDay, endYear, endMonth, endDay) == 1)
    {
        printf("gg");
        return 0;
    }

    // 년도에 따른 일수차
    for (int i = toYear+1; i < endYear; i++)
    {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) sumDay += 366;
        else sumDay += 365;
    }
    
    // 달에 따른 일수차
    if (toYear == endYear)
    {
        for (int i = toMonth; i < endMonth-1; i++)
        {
            if ((i == 1 && toYear % 4 == 0 && toYear % 100 != 0) || (i == 1 && toYear % 400 == 0)) sumDay += 29;
            else sumDay += days[i];
        }
    }
    else
    {
        for (int i = toMonth; i < 12; i++)
        {
            if ((i == 1 && toYear % 4 == 0 && toYear % 100 != 0) || (i == 1 && toYear % 400 == 0)) sumDay += 29;
            else sumDay += days[i];
        }
        for (int i = 0; i < endMonth-1; i++)
        {
            if ((i == 1 && endYear % 4 == 0 && endYear % 100 != 0) || (i == 1 && endYear % 400 == 0)) sumDay += 29;
            else sumDay += days[i];
        }
    }

    // 일에 따른 일수차
    if (toYear == endYear && toMonth == endMonth)
    {
        sumDay += endDay - toDay;
    }
    else
    {
        if ((toMonth == 2 && toYear % 4 == 0 && toYear % 100 != 0) || (toMonth == 2 && toYear % 400 == 0)) 
        {
            sumDay += (29 - toDay);
        }
        else sumDay += (days[toMonth -1] - toDay);
        sumDay += endDay;
    }
    
    printf("D-%d", sumDay);
    return 0;
}

int check_thousand_year(int criYear, int criMonth, int criDay, int comYear, int comMonth, int comDay)
{
    if (criYear + 1000 < comYear) return 1;
    else if (criYear + 1000 == comYear)
    {
        if (criMonth < comMonth) return 1;
        else if (criMonth == comMonth)
        {
            if (criDay <= comDay) return 1;
        }
    }
    return 0;
}