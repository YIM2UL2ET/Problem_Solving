#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, x, max, sum, count;
    cin >> n >> x;

    vector <int> values(x);

    sum = 0;
    for (int i = 0; i < x; i++) {
        cin >> values[i];
        sum += values[i];
    }

    max = sum;
    count = 1;
    for (int i = x; i < n; i++) {
        sum -= values[i % x];
        cin >> values[i % x];
        sum += values[i % x];

        if (max == sum) count++;
        else if (max < sum) {
            max = sum;
            count = 1;
        }
    }

    if (max == 0) cout << "SAD";
    else cout << max << '\n' << count;
    
    return 0;
}