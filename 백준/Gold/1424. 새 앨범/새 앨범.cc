#include <iostream>

int main(void)
{
    using namespace std;

    int i, n, l, c;
    cin >> n;
    cin >> l;
    cin >> c;

    for (i = 1; l * i + (i - 1) <= c; i++) {}
    i--;

    if (i % 13 == 0) i--;

    if (n % i == 0) cout << n / i;
    else if (n % i % 13 == 0)
    {
        if (n / i < 1 || (n % i) + 1 == i) cout << (n / i) + 2;
        else cout << (n / i) + 1;
    }
    else cout << (n / i) + 1;
    
    return 0;
}