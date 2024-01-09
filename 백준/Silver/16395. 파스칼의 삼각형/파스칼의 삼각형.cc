#include <iostream>

using namespace std;

int main(void)
{
    int i, j, n, k;
    cin >> n >> k;
    
    int triangle[n];
    for (i = 0; i < n; i++)
    {
        triangle[i] = 1;
    }
    
    for (i = 1; i < k; i++)
    {
        for (j = 1; j < n; j++)
        {
            triangle[j] += triangle[j-1];
        }
    }
    
    cout << triangle[n-k];
    return 0;
}