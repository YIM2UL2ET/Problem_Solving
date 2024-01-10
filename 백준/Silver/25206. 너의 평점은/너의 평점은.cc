#include <iostream>

using namespace std;

int main(void)
{
    double total = 0, a, n;
    int i;
    string str;

    for (i = 0; i < 20; i++)
    {
        cin >> str >> a >> str;
        if (str == "P") continue;
        else if (str == "A+") total += a * 4.5;
        else if (str == "A0") total += a * 4.0;
        else if (str == "B+") total += a * 3.5;
        else if (str == "B0") total += a * 3.0;
        else if (str == "C+") total += a * 2.5;
        else if (str == "C0") total += a * 2.0;
        else if (str == "D+") total += a * 1.5;
        else if (str == "D0") total += a * 1.0;
        n += a;
    }
    
    cout << total / n;

    return 0;
}