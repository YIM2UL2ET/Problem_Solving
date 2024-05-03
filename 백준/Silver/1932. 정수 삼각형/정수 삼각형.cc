#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, result;
    vector <int> before(1);

    cin >> n >> before[0];
    result = before[0];

    for (int cnt = 1; cnt < n; cnt++) {
        vector <int> now(cnt+1);

        for (int idx = 0; idx <= cnt; idx++) {
            cin >> now[idx];

            if (idx-1 < 0) now[idx] += before[idx];
            else if (idx >= cnt) now[idx] += before[idx-1];
            else now[idx] += before[idx-1] > before[idx] ? before[idx-1] : before[idx];

            result = result > now[idx] ? result : now[idx];
        }

        before = now;
    }
    
    cout << result;
    return 0;
}