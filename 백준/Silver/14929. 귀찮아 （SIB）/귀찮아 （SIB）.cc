#include <iostream>

using namespace std;

int main(void)
{
    int i, j, n, a, b;
    long long result = 0, total = 0;
    cin >> n;
    int ary[n];

    for (i = 0; i < n; i++)
    {
        cin >> ary[i];
        total += ary[i];
    }

    for (i = 0; i < n-1; i++)
    {
        total -= ary[i];
        result += total * ary[i];
    }
    
    cout << result;

    return 0;
}