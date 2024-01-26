#include <iostream>
#include <ctime>

int main(void)
{
    time_t timer = time(NULL);
    struct tm* t;

    t = localtime(&timer);
    std::cout << t->tm_year + 1900 << "-";
    if (t->tm_mon + 1 < 10) std::cout << "0";
    std::cout << t->tm_mon + 1 << "-";
    if (t->tm_mday < 10) std::cout << "0";
    std::cout << t->tm_mday;
    return 0;
}