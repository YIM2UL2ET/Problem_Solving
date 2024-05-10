#include <iostream>
#include <vector>
using namespace std;

int maxVolum;
vector <int> volums;
vector <vector <bool>> dp;

int Adjust(int index, int nowVolum) {
    if (index == volums.size()) return nowVolum;
    else if (!dp[index][nowVolum]) {
        dp[index][nowVolum] = true;

        int up = -1, down = -1;
        if (nowVolum + volums[index] <= maxVolum) {
            up = Adjust(index+1, nowVolum + volums[index]);
        }
        if (nowVolum - volums[index] >= 0) {
            down = Adjust(index+1, nowVolum - volums[index]);
        }
        return max(up, down);
    }
    else return -1;
}

int main(void) {
    int n, start;
    cin >> n >> start >> maxVolum;

    volums.resize(n);
    dp.resize(n, vector <bool> (maxVolum, false));
    for (int &volum : volums) {
        cin >> volum;
    }

    cout << Adjust(0, start);
    return 0;
}