#include <iostream>
using namespace std;

int main(void) {
    int k, p, ans;
    string str;
    
    cin >> str;
    k = 0, p = 0, ans = 0;
    for (char ch : str) {
        if (ch == 'K') {
            k++;
            p = max(0, p - 1);
        } else {
            p++;
            k = max(0, k - 1);
        }
        ans = max(ans, max(k, p));
    }

    cout << ans;

    return 0;
}