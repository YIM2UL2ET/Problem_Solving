#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num, max, sum;

    cin >> n;
    max = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (sum < 200001) sum += num;
        if (max < num) max = num;
    }

    if (n == 1 && sum > 1) {
        cout << "Unhappy";
    } else if (n > 1 && max > sum - max) {
        cout << "Unhappy";
    } else {
        cout << "Happy";
    }

    return 0;
}